#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

static JavaVM* jvm = 0;

static jobject idleFuncGlobalRef = 0; // TODO: DPP: 190105T120200: It's got a memory leak when the jvm shuts down because idleFuncGlobalRef is never de-allocated.

static void delegate() {
	DPRINTF("IdleFunc delegate() called.\n");

	JNIEnv* env;
	(*jvm)->AttachCurrentThread(jvm, (void**)&env, NULL);
//	DPRINTF("env == %p\n", env);

//	DPRINTF("idleFuncGlobalRef == %p\n", idleFuncGlobalRef);
	jclass idleFuncJClass = (*env)->GetObjectClass(env, idleFuncGlobalRef); // get interface from idleFunc

//	DPRINTF("idleFuncJClass == %p\n", idleFuncJClass);
	jmethodID idleJMethodID = (*env)->GetMethodID(env, idleFuncJClass, "idle", "()V");

//	DPRINTF("idleJMethodID == %p\n", idleJMethodID);
	(*env)->CallVoidMethod(env, idleFuncGlobalRef, idleJMethodID);

	(*jvm)->DetachCurrentThread(jvm);
}

JNIEXPORT void JNICALL Java_com_pflager_glut_glutIdleFunc(JNIEnv* env, jobject object, jobject idleFunc) {
	DPRINTF("glutIdleFunc(%p)\n", idleFunc);

	if (idleFunc == NULL) {
		// TODO: DPP: 190106T141700: if a global ref has been registered, unregister it.
		if (idleFuncGlobalRef) {
			(*env)->DeleteGlobalRef(env, idleFuncGlobalRef);
			idleFuncGlobalRef = 0;
		}
		glutIdleFunc(NULL);
		return;
	}

	(*env)->GetJavaVM(env, &jvm); //store jvm reference for later

//	DPRINTF("object == %p\n", object);
//	DPRINTF("idleFunc == %p\n", idleFunc);
	jclass idleFuncJClass = (*env)->GetObjectClass(env, idleFunc); // get interface from idleFunc
//	DPRINTF("idleFuncJClass == %p\n", idleFuncJClass);

	idleFuncGlobalRef = (*env)->NewGlobalRef(env, idleFunc); // Prevent the idleFunc object from being garbage collected.
//	DPRINTF("idleFuncGlobalRef == %p\n", idleFuncGlobalRef);

	// get idle() method from interface to make sure idleFunc has one.
	jmethodID idleJMethodID = (*env)->GetMethodID(env, idleFuncJClass, "idle", "()V");
//	DPRINTF("idleJMethodID == %p\n", idleJMethodID);
	if (NULL == idleJMethodID) {
		jmethodID getClassJMethodID = (*env)->GetMethodID(env, idleFuncJClass, "getClass", "()Ljava/lang/Class;"); // get jmethodID of getClass() method.
        jobject classJObject = (*env)->CallObjectMethod(env, idleFuncJClass, getClassJMethodID); // Call getClass() to retrieve a jobject to its class.

        jclass classJClass = (*env)->GetObjectClass(env, classJObject); // get the jclass of the classJObject

        jmethodID getNameJMethodID = (*env)->GetMethodID(env, classJClass, "getName", "()Ljava/lang/String;"); // get jmethodID of getName() method.
        jstring classNameJString = (*env)->CallObjectMethod(env, classJClass, getNameJMethodID); // call getName() on classJClass to retrieve the class' jstring name
        const char *className = (*env)->GetStringUTFChars(env, classNameJString, NULL); // retrieve a const char* to the UTF representation of the string.

        char s[128 + strlen(className)];

        sprintf(s, "Class %s has no public void idle() override.", className);
        (*env)->ReleaseStringUTFChars(env, classNameJString, className);
        jclass IllegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, IllegalArgumentException, s);
        return; // ThrowNew never returns anyway. This keeps the compiler happy.
	}

	glutIdleFunc(delegate);
}
