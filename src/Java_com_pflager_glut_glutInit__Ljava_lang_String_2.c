#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutInit__Ljava_lang_String_2(JNIEnv *env, jobject object, jstring argJString) {
	DPRINTF("glutInit(%p);\n", argJString);

	int argc = 2;
	char* argv[2];

	argv[0] = "jglut";

	const char *inCStr = (*env)->GetStringUTFChars(env, argJString, NULL);
	if (NULL == inCStr) {
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		(*env)->ThrowNew(env, illegalArgumentException, "You must pass a non-null String");
		return;
	}

	argv[1] = (char*)inCStr;

	glutInit(&argc, (char**)&argv);

	// Step 2: Perform its intended operations
	DPRINTF("In C, the received string is: %s\n", inCStr);
	(*env)->ReleaseStringUTFChars(env, argJString, inCStr);  // release resources
}
