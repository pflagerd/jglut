#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

void* glInterleavedArrays_doublebuffer;

JNIEXPORT void JNICALL Java_com_pflager_gl_glInterleavedArrays__II_3D(JNIEnv *env, jobject object, jint format, jint stride, jdoubleArray ptrJDoubleArray) {
    DPRINTF("glInterleavedArrays(%d, %d, 0x%p);\n", format, stride, ptrJDoubleArray);
	if (ptrJDoubleArray == NULL) {
		return;
	}

	jsize length = (*env)->GetArrayLength(env, ptrJDoubleArray);
	DPRINTF("length == %d\n", length);
	if (length == 0) {
		return;
	}

	jdouble *jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, ptrJDoubleArray, NULL);

	if (glInterleavedArrays_doublebuffer != 0) {
		DPRINTF("Freeing glInterleavedArrays_doublebuffer before re-calloc()ing it.");
		free(glInterleavedArrays_doublebuffer);
	}

	glInterleavedArrays_doublebuffer = calloc(length, sizeof(jfloat)); // (sic) jfloat, because all variants deal with 4-byte (32bit) quantities, whether float or unsigned byte (x4).

	for (unsigned i = 0; i < length; i++) {
		((jfloat*)glInterleavedArrays_doublebuffer)[i] = jdoubleArrayElements[i];
	}

	(*env)->ReleaseDoubleArrayElements(env, ptrJDoubleArray, jdoubleArrayElements, 0); // release resources

	glInterleavedArrays(format, stride, glInterleavedArrays_doublebuffer);
}
