#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

void* glInterleavedArrays_intbuffer;

JNIEXPORT void JNICALL Java_com_pflager_gl_glInterleavedArrays__II_3I(JNIEnv *env, jobject object, jint format, jint stride, jintArray ptrJIntArray) {
    DPRINTF("glInterleavedArrays(%d, %d, 0x%p);\n", format, stride, ptrJIntArray);
	if (ptrJIntArray == NULL) {
		return;
	}

	jsize length = (*env)->GetArrayLength(env, ptrJIntArray);
	if (length == 0) {
		return;
	}

	jint *jintArrayElements = (*env)->GetIntArrayElements(env, ptrJIntArray, NULL);

	if (glInterleavedArrays_intbuffer != 0) {
		DPRINTF("Freeing glInterleavedArrays_intbuffer before re-calloc()ing it.");
		free(glInterleavedArrays_intbuffer);
	}

	glInterleavedArrays_intbuffer = calloc(length, sizeof(jint));

	memcpy(glInterleavedArrays_intbuffer, jintArrayElements, length * sizeof(jint));

	(*env)->ReleaseIntArrayElements(env, ptrJIntArray, jintArrayElements, 0); // release resources

	glInterleavedArrays(format, stride, glInterleavedArrays_intbuffer);
}
