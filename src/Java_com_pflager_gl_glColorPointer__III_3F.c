#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

void* glColorPointer_floatbuffer;	// Initially zero.
									// Set each time this function is called.
									// If non-zero when the function is called, it is freed.
									// Not sure if at_exit() will work with java.

JNIEXPORT void JNICALL Java_com_pflager_gl_glColorPointer__III_3F(JNIEnv *env, jobject object, jint size, jint type, jint stride, jfloatArray ptrJFloatArray) {
    DPRINTF("glColorPointer(%d, %d, %d, 0x%p);\n", size, type, stride, ptrJFloatArray);
	if (ptrJFloatArray == NULL) {
		return;
	}

	jsize length = (*env)->GetArrayLength(env, ptrJFloatArray);
	if (length == 0) {
		return;
	}

	jfloat *jfloatArrayElements = (*env)->GetFloatArrayElements(env, ptrJFloatArray, NULL);

	if (glColorPointer_floatbuffer != 0) {
		DPRINTF("Freeing glColorPointer_floatbuffer before re-calloc()ing it.");
		free(glColorPointer_floatbuffer);
	}

	glColorPointer_floatbuffer = calloc(length, sizeof(jfloat));

	memcpy(glColorPointer_floatbuffer, jfloatArrayElements, length * sizeof(jfloat));

	(*env)->ReleaseFloatArrayElements(env, ptrJFloatArray, jfloatArrayElements, 0); // release resources

	glColorPointer(size, GL_FLOAT, stride, glColorPointer_floatbuffer);
}
