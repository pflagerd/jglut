#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glDrawElements__III_3I(JNIEnv *env, jobject object, jint mode, jint count, jint type, jintArray indicesJIntArray) {
    DPRINTF("glDrawElements(%d, %d, %d, 0x%p);\n", mode, count, type, indicesJIntArray);
	if (indicesJIntArray == NULL) {
		return;
	}

	jsize length = (*env)->GetArrayLength(env, indicesJIntArray);
	if (length == 0) {
		return;
	}

	jint *jintArrayElements = (*env)->GetIntArrayElements(env, indicesJIntArray, NULL);

	void* intArray = calloc(length, sizeof(jint));

	memcpy(intArray, jintArrayElements, length * sizeof(jint));

	(*env)->ReleaseIntArrayElements(env, indicesJIntArray, jintArrayElements, 0); // release resources

    glDrawElements(mode, count, type, intArray);

    free(intArray);
}
