#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

void* glVertexPointer_floatbuffer;	// Initially zero.
// Set each time this function is called.
// If non-zero when the function is called, it is freed.
// Not sure if at_exit() will work with java.

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertexPointer__III_3F(JNIEnv *env, jobject object, jint size, jint type, jint stride, jfloatArray ptrJFloatArray) {
	DPRINTF("glVertexPointer(%d, %d, %d, 0x%p);\n", size, type, stride, ptrJFloatArray);
	
	if (ptrJFloatArray == NULL) {
		return;
	}

	jsize length = (*env)->GetArrayLength(env, ptrJFloatArray);
	if (length == 0) {
		return;
	}

	jfloat *jfloatArrayElements = (*env)->GetFloatArrayElements(env, ptrJFloatArray, NULL);

	if (glVertexPointer_floatbuffer != 0) {
		DPRINTF("Freeing glVertexPointer_floatbuffer before re-calloc()ing it.");
		free(glVertexPointer_floatbuffer);
	}

	glVertexPointer_floatbuffer = calloc(length, sizeof(jfloat));

	memcpy(glVertexPointer_floatbuffer, jfloatArrayElements, length * sizeof(jfloat));

	(*env)->ReleaseFloatArrayElements(env, ptrJFloatArray, jfloatArrayElements, 0); // release resources

	glVertexPointer(size, GL_FLOAT, stride, glVertexPointer_floatbuffer);
}
