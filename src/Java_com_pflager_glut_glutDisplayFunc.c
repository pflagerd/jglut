#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

static JavaVM* jvm = 0;

static jobject displayFuncGlobalRef; // TODO: DPP: 190105T120200: It's got a memory leak when the jvm shuts down because displayFuncGlobalRef is never de-allocated.

static void delegate() {
	DPRINTF("DisplayFunc delegate() called.\n");

	JNIEnv* env;
	(*jvm)->AttachCurrentThread(jvm, (void**)&env, NULL);
//	DPRINTF("env == %p\n", env);

//	DPRINTF("displayFuncGlobalRef == %p\n", displayFuncGlobalRef);
	jclass displayFuncJClass = (*env)->GetObjectClass(env, displayFuncGlobalRef); // get interface from displayFunc

//	DPRINTF("displayFuncJClass == %p\n", displayFuncJClass);
	jmethodID displayJMethodID = (*env)->GetMethodID(env, displayFuncJClass, "display", "()V");

//	DPRINTF("displayJMethodID == %p\n", displayJMethodID);
	(*env)->CallVoidMethod(env, displayFuncGlobalRef, displayJMethodID);

	(*jvm)->DetachCurrentThread(jvm);
}

JNIEXPORT void JNICALL Java_com_pflager_glut_glutDisplayFunc(JNIEnv* env, jobject object, jobject displayFunc) {
	DPRINTF("glutDisplayFunc(%p)\n", displayFunc);

	if (displayFunc == NULL) {
		// TODO: DPP: 190106T141700: if a global ref has been registered, unregister it.
		if (displayFuncGlobalRef) {
			(*env)->DeleteGlobalRef(env, displayFuncGlobalRef);
			displayFuncGlobalRef = 0;
		}
		glutDisplayFunc(NULL);
		return;
	}

//	DPRINTF("object == %p\n", object);
//	DPRINTF("displayFunc == %p\n", displayFunc);
	jclass displayFuncJClass = (*env)->GetObjectClass(env, displayFunc); // get interface from displayFunc
//	DPRINTF("displayFuncJClass == %p\n", displayFuncJClass);

	(*env)->GetJavaVM(env, &jvm); //store jvm reference for later

	displayFuncGlobalRef = (*env)->NewGlobalRef(env, displayFunc); // Prevent the displayFunc object from being garbage collected.
//	DPRINTF("displayFuncGlobalRef == %p\n", displayFuncGlobalRef);

	// get display() method from interface to make sure displayFunc has one.
	jmethodID displayJMethodID = (*env)->GetMethodID(env, displayFuncJClass, "display", "()V");
//	DPRINTF("displayJMethodID == %p\n", displayJMethodID);
	if (NULL == displayJMethodID) {
		jmethodID getClassJMethodID = (*env)->GetMethodID(env, displayFuncJClass, "getClass", "()Ljava/lang/Class;"); // get jmethodID of getClass() method.
        jobject classJObject = (*env)->CallObjectMethod(env, displayFuncJClass, getClassJMethodID); // Call getClass() to retrieve a jobject to its class.

        jclass classJClass = (*env)->GetObjectClass(env, classJObject); // get the jclass of the classJObject

        jmethodID getNameJMethodID = (*env)->GetMethodID(env, classJClass, "getName", "()Ljava/lang/String;"); // get jmethodID of getName() method.
        jstring classNameJString = (*env)->CallObjectMethod(env, classJClass, getNameJMethodID); // call getName() on classJClass to retrieve the class' jstring name
        const char *className = (*env)->GetStringUTFChars(env, classNameJString, NULL); // retrieve a const char* to the UTF representation of the string.

        char s[128 + strlen(className)];

        sprintf(s, "Class %s has no public void display() override.", className);
        (*env)->ReleaseStringUTFChars(env, classNameJString, className);
        jclass IllegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, IllegalArgumentException, s);
        return; // ThrowNew never returns anyway. This keeps the compiler happy.
	}

	glutDisplayFunc(delegate);
}
