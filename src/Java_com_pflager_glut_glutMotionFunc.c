#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

static JavaVM* jvm = 0;

static jobject motionFuncGlobalRef; // TODO: DPP: 190105T120200: It's got a memory leak when the jvm shuts down because motionFuncGlobalRef is never de-allocated.

static void delegate(int x, int y) {
	DPRINTF("MotionFunc delegate(%d, %d)\n", x, y);

	JNIEnv* env;
	(*jvm)->AttachCurrentThread(jvm, (void**)&env, NULL);
//	DPRINTF("env == %p\n", env);

//	DPRINTF("motionFuncGlobalRef == %p\n", motionFuncGlobalRef);
	jclass motionFuncJClass = (*env)->GetObjectClass(env, motionFuncGlobalRef); // get interface from motionFunc

//	DPRINTF("motionFuncJClass == %p\n", motionFuncJClass);
	jmethodID motionJMethodID = (*env)->GetMethodID(env, motionFuncJClass, "motion", "(II)V");

//	DPRINTF("motionJMethodID == %p\n", motionJMethodID);
	(*env)->CallVoidMethod(env, motionFuncGlobalRef, motionJMethodID, x, y);

	(*jvm)->DetachCurrentThread(jvm);
}

JNIEXPORT void JNICALL Java_com_pflager_glut_glutMotionFunc(JNIEnv* env, jobject object, jobject motionFunc) {
	DPRINTF("glutMotionFunc(%p)\n", motionFunc);

	if (motionFunc == NULL) {
		// TODO: DPP: 190106T141700: if a global ref has been registered, unregister it.
		if (motionFuncGlobalRef) {
			(*env)->DeleteGlobalRef(env, motionFuncGlobalRef);
			motionFuncGlobalRef = 0;
		}
		glutMotionFunc(NULL);
		return;
	}

//	DPRINTF("object == %p\n", object);
//	DPRINTF("motionFunc == %p\n", motionFunc);
	jclass motionFuncJClass = (*env)->GetObjectClass(env, motionFunc); // get interface from motionFunc
//	DPRINTF("motionFuncJClass == %p\n", motionFuncJClass);

	(*env)->GetJavaVM(env, &jvm); //store jvm reference for later

	motionFuncGlobalRef = (*env)->NewGlobalRef(env, motionFunc); // Prevent the motionFunc object from being garbage collected.
//	DPRINTF("motionFuncGlobalRef == %p\n", motionFuncGlobalRef);

	// get motion() method from interface to make sure motionFunc has one.
	jmethodID motionJMethodID = (*env)->GetMethodID(env, motionFuncJClass, "motion", "(II)V");
//	DPRINTF("motionJMethodID == %p\n", motionJMethodID);
	if (NULL == motionJMethodID) {
		jmethodID getClassJMethodID = (*env)->GetMethodID(env, motionFuncJClass, "getClass", "()Ljava/lang/Class;"); // get jmethodID of getClass() method.
        jobject classJObject = (*env)->CallObjectMethod(env, motionFuncJClass, getClassJMethodID); // Call getClass() to retrieve a jobject to its class.

        jclass classJClass = (*env)->GetObjectClass(env, classJObject); // get the jclass of the classJObject

        jmethodID getNameJMethodID = (*env)->GetMethodID(env, classJClass, "getName", "()Ljava/lang/String;"); // get jmethodID of getName() method.
        jstring classNameJString = (*env)->CallObjectMethod(env, classJClass, getNameJMethodID); // call getName() on classJClass to retrieve the class' jstring name
        const char *className = (*env)->GetStringUTFChars(env, classNameJString, NULL); // retrieve a const char* to the UTF representation of the string.

        char s[128 + strlen(className)];

        sprintf(s, "Class %s has no public void motion() override.", className);
        (*env)->ReleaseStringUTFChars(env, classNameJString, className);
        jclass IllegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, IllegalArgumentException, s);
        return; // ThrowNew never returns anyway. This keeps the compiler happy.
	}

	glutMotionFunc(delegate);
}
