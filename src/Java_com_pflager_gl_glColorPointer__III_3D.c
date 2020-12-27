#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

void* glColorPointer_doublebuffer;	// Initially zero.
									// Set each time this function is called.
									// If non-zero when the function is called, it is freed.
									// Not sure if at_exit() will work with java.

JNIEXPORT void JNICALL Java_com_pflager_gl_glColorPointer__III_3D(JNIEnv *env, jobject object, jint size, jint type, jint stride, jdoubleArray ptrJDoubleArray) {
	DPRINTF("glColorPointer(%d, %d, %d, %p);\n", size, type, stride, ptrJDoubleArray);
	if (ptrJDoubleArray == NULL) {
		return;
	}

	jsize length = (*env)->GetArrayLength(env, ptrJDoubleArray);
	if (length == 0) {
		return;
	}

	jdouble *jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, ptrJDoubleArray, NULL);

	if (glColorPointer_doublebuffer != 0) {
		DPRINTF("Freeing glColorPointer_doublebuffer before re-calloc()ing it.");
		free(glColorPointer_doublebuffer);
	}

	glColorPointer_doublebuffer = calloc(length, sizeof(jdouble));

	memcpy(glColorPointer_doublebuffer, jdoubleArrayElements, length * sizeof(jdouble));

	(*env)->ReleaseDoubleArrayElements(env, ptrJDoubleArray, jdoubleArrayElements, 0); // release resources

	glColorPointer(size, GL_DOUBLE, stride, glColorPointer_doublebuffer);
}
