#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glDrawElements__III_3B(JNIEnv *env, jobject object, jint mode, jint count, jint type, jbyteArray indicesJByteArray) {
    DPRINTF("glDrawElements(%d, %d, %d, 0x%p);\n", mode, count, type, indicesJByteArray);
	if (indicesJByteArray == NULL) {
		return;
	}

	jsize length = (*env)->GetArrayLength(env, indicesJByteArray);
	if (length == 0) {
		return;
	}

	jbyte *jbyteArrayElements = (*env)->GetByteArrayElements(env, indicesJByteArray, NULL);

	void* byteArray = calloc(length, sizeof(jbyte));

	memcpy(byteArray, jbyteArrayElements, length * sizeof(jbyte));

	(*env)->ReleaseByteArrayElements(env, indicesJByteArray, jbyteArrayElements, 0); // release resources

    glDrawElements(mode, count, type, byteArray);

    free(byteArray);
}
