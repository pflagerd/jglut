#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

static JavaVM* jvm = 0;

static jobject mouseFuncGlobalRef; // TODO: DPP: 190105T120200: It's got a memory leak when the jvm shuts down because mouseFuncGlobalRef is never de-allocated.

static void delegate(int button, int state, int x, int y) {
	DPRINTF("MouseFunc delegate(%d, %d, %d, %d)\n", button, state, x, y);

	JNIEnv* env;
	(*jvm)->AttachCurrentThread(jvm, (void**)&env, NULL);
//	DPRINTF("env == %p\n", env);

//	DPRINTF("mouseFuncGlobalRef == %p\n", mouseFuncGlobalRef);
	jclass mouseFuncJClass = (*env)->GetObjectClass(env, mouseFuncGlobalRef); // get interface from mouseFunc

//	DPRINTF("mouseFuncJClass == %p\n", mouseFuncJClass);
	jmethodID mouseJMethodID = (*env)->GetMethodID(env, mouseFuncJClass, "mouse", "(IIII)V");

//	DPRINTF("mouseJMethodID == %p\n", mouseJMethodID);
	(*env)->CallVoidMethod(env, mouseFuncGlobalRef, mouseJMethodID, button, state, x, y);

	(*jvm)->DetachCurrentThread(jvm);
}

JNIEXPORT void JNICALL Java_com_pflager_glut_glutMouseFunc(JNIEnv* env, jobject object, jobject mouseFunc) {
	DPRINTF("glutMouseFunc(%p)\n", mouseFunc);

	if (mouseFunc == NULL) {
		// TODO: DPP: 190106T141700: if a global ref has been registered, unregister it.
		if (mouseFuncGlobalRef) {
			(*env)->DeleteGlobalRef(env, mouseFuncGlobalRef);
			mouseFuncGlobalRef = 0;
		}
		glutIdleFunc(NULL);
		return;
	}

//	DPRINTF("object == %p\n", object);
//	DPRINTF("mouseFunc == %p\n", mouseFunc);
	jclass mouseFuncJClass = (*env)->GetObjectClass(env, mouseFunc); // get interface from mouseFunc
//	DPRINTF("mouseFuncJClass == %p\n", mouseFuncJClass);

	(*env)->GetJavaVM(env, &jvm); //store jvm reference for later

	mouseFuncGlobalRef = (*env)->NewGlobalRef(env, mouseFunc); // Prevent the mouseFunc object from being garbage collected.
//	DPRINTF("mouseFuncGlobalRef == %p\n", mouseFuncGlobalRef);

	// get mouse() method from interface to make sure mouseFunc has one.
	jmethodID mouseJMethodID = (*env)->GetMethodID(env, mouseFuncJClass, "mouse", "(IIII)V");
//	DPRINTF("mouseJMethodID == %p\n", mouseJMethodID);
	if (NULL == mouseJMethodID) {
		jmethodID getClassJMethodID = (*env)->GetMethodID(env, mouseFuncJClass, "getClass", "()Ljava/lang/Class;"); // get jmethodID of getClass() method.
        jobject classJObject = (*env)->CallObjectMethod(env, mouseFuncJClass, getClassJMethodID); // Call getClass() to retrieve a jobject to its class.

        jclass classJClass = (*env)->GetObjectClass(env, classJObject); // get the jclass of the classJObject

        jmethodID getNameJMethodID = (*env)->GetMethodID(env, classJClass, "getName", "()Ljava/lang/String;"); // get jmethodID of getName() method.
        jstring classNameJString = (*env)->CallObjectMethod(env, classJClass, getNameJMethodID); // call getName() on classJClass to retrieve the class' jstring name
        const char *className = (*env)->GetStringUTFChars(env, classNameJString, NULL); // retrieve a const char* to the UTF representation of the string.

        char s[128 + strlen(className)];

        sprintf(s, "Class %s has no public void mouse() override.", className);
        (*env)->ReleaseStringUTFChars(env, classNameJString, className);
        jclass IllegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, IllegalArgumentException, s);
        return; // ThrowNew never returns anyway. This keeps the compiler happy.
	}

	glutMouseFunc(delegate);
}
