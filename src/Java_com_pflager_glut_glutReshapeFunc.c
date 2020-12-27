#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

static JavaVM* jvm = 0;

static jobject reshapeFuncGlobalRef; // TODO: DPP: 190105T120200: It's got a memory leak when the jvm shuts down because reshapeFuncGlobalRef is never de-allocated.

static void delegate(int x, int y) {
	DPRINTF("ReshapeFunc delegate(%d, %d)\n", x, y);

	JNIEnv* env;
	(*jvm)->AttachCurrentThread(jvm, (void**)&env, NULL);
//	DPRINTF("env == %p\n", env);

//	DPRINTF("reshapeFuncGlobalRef == %p\n", reshapeFuncGlobalRef);
	jclass reshapeFuncJClass = (*env)->GetObjectClass(env, reshapeFuncGlobalRef); // get interface from reshapeFunc

//	DPRINTF("reshapeFuncJClass == %p\n", reshapeFuncJClass);
	jmethodID reshapeJMethodID = (*env)->GetMethodID(env, reshapeFuncJClass, "reshape", "(II)V");

//	DPRINTF("reshapeJMethodID == %p\n", reshapeJMethodID);
	(*env)->CallVoidMethod(env, reshapeFuncGlobalRef, reshapeJMethodID, x, y);

	(*jvm)->DetachCurrentThread(jvm);
}

JNIEXPORT void JNICALL Java_com_pflager_glut_glutReshapeFunc(JNIEnv* env, jobject object, jobject reshapeFunc) {
	DPRINTF("glutReshapeFunc(%p)\n", reshapeFunc);

	if (reshapeFunc == NULL) {
		// TODO: DPP: 190106T141700: if a global ref has been registered, unregister it.
		if (reshapeFuncGlobalRef) {
			(*env)->DeleteGlobalRef(env, reshapeFuncGlobalRef);
			reshapeFuncGlobalRef = 0;
		}
		glutReshapeFunc(NULL);
		return;
	}

//	DPRINTF("object == %p\n", object);
//	DPRINTF("reshapeFunc == %p\n", reshapeFunc);
	jclass reshapeFuncJClass = (*env)->GetObjectClass(env, reshapeFunc); // get interface from reshapeFunc
//	DPRINTF("reshapeFuncJClass == %p\n", reshapeFuncJClass);

	(*env)->GetJavaVM(env, &jvm); //store jvm reference for later

	reshapeFuncGlobalRef = (*env)->NewGlobalRef(env, reshapeFunc); // Prevent the reshapeFunc object from being garbage collected.
//	DPRINTF("reshapeFuncGlobalRef == %p\n", reshapeFuncGlobalRef);

	// get reshape() method from interface to make sure reshapeFunc has one.
	jmethodID reshapeJMethodID = (*env)->GetMethodID(env, reshapeFuncJClass, "reshape", "(II)V");
//	DPRINTF("reshapeJMethodID == %p\n", reshapeJMethodID);
	if (NULL == reshapeJMethodID) {
		jmethodID getClassJMethodID = (*env)->GetMethodID(env, reshapeFuncJClass, "getClass", "()Ljava/lang/Class;"); // get jmethodID of getClass() method.
        jobject classJObject = (*env)->CallObjectMethod(env, reshapeFuncJClass, getClassJMethodID); // Call getClass() to retrieve a jobject to its class.

        jclass classJClass = (*env)->GetObjectClass(env, classJObject); // get the jclass of the classJObject

        jmethodID getNameJMethodID = (*env)->GetMethodID(env, classJClass, "getName", "()Ljava/lang/String;"); // get jmethodID of getName() method.
        jstring classNameJString = (*env)->CallObjectMethod(env, classJClass, getNameJMethodID); // call getName() on classJClass to retrieve the class' jstring name
        const char *className = (*env)->GetStringUTFChars(env, classNameJString, NULL); // retrieve a const char* to the UTF representation of the string.

        char s[128 + strlen(className)];

        sprintf(s, "Class %s has no public void reshape() override.", className);
        (*env)->ReleaseStringUTFChars(env, classNameJString, className);
        jclass IllegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, IllegalArgumentException, s);
        return; // ThrowNew never returns anyway. This keeps the compiler happy.
	}

	glutReshapeFunc(delegate);
}
