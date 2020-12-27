#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

void* glInterleavedArrays_floatbuffer;

JNIEXPORT void JNICALL Java_com_pflager_gl_glInterleavedArrays__II_3F(JNIEnv *env, jobject object, jint format, jint stride, jfloatArray ptrJFloatArray) {
    DPRINTF("glInterleavedArrays(%d, %d, 0x%p);\n", format, stride, ptrJFloatArray);
	if (ptrJFloatArray == NULL) {
		return;
	}

	jsize length = (*env)->GetArrayLength(env, ptrJFloatArray);
	if (length == 0) {
		return;
	}

	jfloat *jfloatArrayElements = (*env)->GetFloatArrayElements(env, ptrJFloatArray, NULL);

	if (glInterleavedArrays_floatbuffer != 0) {
		DPRINTF("Freeing glInterleavedArrays_floatbuffer before re-calloc()ing it.");
		free(glInterleavedArrays_floatbuffer);
	}

	glInterleavedArrays_floatbuffer = calloc(length, sizeof(jfloat));

	memcpy(glInterleavedArrays_floatbuffer, jfloatArrayElements, length * sizeof(jfloat));

	(*env)->ReleaseFloatArrayElements(env, ptrJFloatArray, jfloatArrayElements, 0); // release resources

	glInterleavedArrays(format, stride, glInterleavedArrays_floatbuffer);
}
