#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glDrawElements__III_3S(JNIEnv *env, jobject object, jint mode, jint count, jint type, jshortArray indicesJShortArray) {
    DPRINTF("glDrawElements(%d, %d, %d, 0x%p);\n", mode, count, type, indicesJShortArray);
	if (indicesJShortArray == NULL) {
		return;
	}

	jsize length = (*env)->GetArrayLength(env, indicesJShortArray);
	if (length == 0) {
		return;
	}

	jshort *jshortArrayElements = (*env)->GetShortArrayElements(env, indicesJShortArray, NULL);

	void* shortArray = calloc(length, sizeof(jshort));

	memcpy(shortArray, jshortArrayElements, length * sizeof(jshort));

	(*env)->ReleaseShortArrayElements(env, indicesJShortArray, jshortArrayElements, 0); // release resources

    glDrawElements(mode, count, type, shortArray);

    free(shortArray);
}
