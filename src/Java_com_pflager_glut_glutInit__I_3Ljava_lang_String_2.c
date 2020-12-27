#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutInit__I_3Ljava_lang_String_2(JNIEnv *env, jobject object, jint argcJInt, jobject argvJObject) {
	DPRINTF("glutInit(%d, {", argcJInt);

	jsize argvJObject_length = (*env)->GetArrayLength(env, argvJObject);
	//DPRINTF("argvJObject_length == %d\n", argvJObject_length);
	assert(argvJObject_length == argcJInt);

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

	int argc = argcJInt;
	glutInit(&argc, argv);

	for (unsigned i = 0; i < argvJObject_length; i++) {
		(*env)->ReleaseStringUTFChars(env, jstrings[i], argv[i]);
	}

	if (argc != argcJInt) { // glut might have removed some of its special arguments
	    jclass notImplementedException = (*env)->FindClass(env, "com/pflager/glut$NotImplementedException");
	    DPRINTF("notImplementedException == %p\n", notImplementedException);
	    (*env)->ThrowNew(env, notImplementedException, "glutInit(): updating array not currently supported.");
	    return;
	}
}
