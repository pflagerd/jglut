#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

static JavaVM* jvm = 0;

static jobject keyboardFuncGlobalRef; // TODO: DPP: 190105T120200: It's got a memory leak when the jvm shuts down because keyboardFuncGlobalRef is never de-allocated.

static void delegate(unsigned char key, int x, int y) {
	DPRINTF("KeyboardFunc delegate(%d, %d, %d)\n", (int)key, x, y);

	JNIEnv* env;
	(*jvm)->AttachCurrentThread(jvm, (void**)&env, NULL);
//	DPRINTF("env == %p\n", env);

//	DPRINTF("keyboardFuncGlobalRef == %p\n", keyboardFuncGlobalRef);
	jclass keyboardFuncJClass = (*env)->GetObjectClass(env, keyboardFuncGlobalRef); // get interface from keyboardFunc

//	DPRINTF("keyboardFuncJClass == %p\n", keyboardFuncJClass);
	jmethodID keyboardJMethodID = (*env)->GetMethodID(env, keyboardFuncJClass, "keyboard", "(CII)V");

//	DPRINTF("keyboardJMethodID == %p\n", keyboardJMethodID);
	(*env)->CallVoidMethod(env, keyboardFuncGlobalRef, keyboardJMethodID, (jchar)key, x, y);

	(*jvm)->DetachCurrentThread(jvm);
}

JNIEXPORT void JNICALL Java_com_pflager_glut_glutKeyboardFunc(JNIEnv *env, jobject object, jobject keyboardFunc){
	DPRINTF("glutKeyboardFunc(%p)\n", keyboardFunc);

	if (keyboardFunc == NULL) {
		// TODO: DPP: 190106T141700: if a global ref has been registered, unregister it.
		if (keyboardFuncGlobalRef) {
			(*env)->DeleteGlobalRef(env, keyboardFuncGlobalRef);
			keyboardFuncGlobalRef = 0;
		}
		glutKeyboardFunc(NULL);
		return;
	}

	jclass keyboardFuncJClass = (*env)->GetObjectClass(env, keyboardFunc); // get interface from keyboardFunc

	(*env)->GetJavaVM(env, &jvm); //store jvm reference for later

	keyboardFuncGlobalRef = (*env)->NewGlobalRef(env, keyboardFunc); // Prevent the keyboardFunc object from being garbage collected.

	// get keyboard() method from interface to make sure keyboardFunc has one.
	jmethodID keyboardJMethodID = (*env)->GetMethodID(env, keyboardFuncJClass, "keyboard", "(CII)V");
	if (NULL == keyboardJMethodID) {
		jmethodID getClassJMethodID = (*env)->GetMethodID(env, keyboardFuncJClass, "getClass", "()Ljava/lang/Class;"); // get jmethodID of getClass() method.
        jobject classJObject = (*env)->CallObjectMethod(env, keyboardFuncJClass, getClassJMethodID); // Call getClass() to retrieve a jobject to its class.

        jclass classJClass = (*env)->GetObjectClass(env, classJObject); // get the jclass of the classJObject

        jmethodID getNameJMethodID = (*env)->GetMethodID(env, classJClass, "getName", "()Ljava/lang/String;"); // get jmethodID of getName() method.
        jstring classNameJString = (*env)->CallObjectMethod(env, classJClass, getNameJMethodID); // call getName() on classJClass to retrieve the class' jstring name
        const char *className = (*env)->GetStringUTFChars(env, classNameJString, NULL); // retrieve a const char* to the UTF representation of the string.

        char s[128 + strlen(className)];

        sprintf(s, "Class %s has no public void keyboard() override.", className);
        (*env)->ReleaseStringUTFChars(env, classNameJString, className);
        jclass IllegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, IllegalArgumentException, s);
        return; // ThrowNew never returns anyway. This keeps the compiler happy.
	}

	glutKeyboardFunc(delegate);
}
