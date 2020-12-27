#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutInit___3Ljava_lang_String_2(JNIEnv *env, jobject object, jobject argvJObject) {
	DPRINTF("glutInit({");

	jsize argvJObject_length = (*env)->GetArrayLength(env, argvJObject);
	//DPRINTF("argvJObject_length == %d\n", argvJObject_length);

	char* argv[argvJObject_length];
	jstring jstrings[argvJObject_length];

	for (unsigned i = 0; i < argvJObject_length; i++) {
		if (i != 0) {
			DPRINTF(", ");
		}
		jstrings[i] = (*env)->GetObjectArrayElement(env, argvJObject, i);
		argv[i] = (char*) (*env)->GetStringUTFChars(env, jstrings[i], NULL);
		DPRINTF("\"%s\"", argv[i]);
	}
	DPRINTF("})\n");

	int argc = argvJObject_length;
	glutInit(&argc, argv);

	for (unsigned i = 0; i < argvJObject_length; i++) {
		(*env)->ReleaseStringUTFChars(env, jstrings[i], argv[i]);
	}

	if (argc != argvJObject_length) { // glut might have removed some of its special arguments
	    jclass notImplementedException = (*env)->FindClass(env, "com/pflager/glut$NotImplementedException");
	    DPRINTF("notImplementedException == %p\n", notImplementedException);
	    (*env)->ThrowNew(env, notImplementedException, "glutInit(): updating array not currently supported.");
	    return;
	}
}
