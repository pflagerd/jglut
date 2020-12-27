#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

void* glVertexPointer_shortbuffer;	// Initially zero.
									// Set each time this function is called.
									// If non-zero when the function is called, it is freed.
									// Not sure if at_exit() will work with java.

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertexPointer__III_3S(JNIEnv *env, jobject object, jint size, jint type, jint stride, jshortArray ptrJShortArray) {
    DPRINTF("glVertexPointer(%d, %d, %d, 0x%p);\n", size, type, stride, ptrJShortArray);
	if (ptrJShortArray == NULL) {
		return;
	}

	jsize length = (*env)->GetArrayLength(env, ptrJShortArray);
	if (length == 0) {
		return;
	}

	jshort *jshortArrayElements = (*env)->GetShortArrayElements(env, ptrJShortArray, NULL);

	if (glVertexPointer_shortbuffer != 0) {
		DPRINTF("Freeing glVertexPointer_shortbuffer before re-calloc()ing it.");
		free(glVertexPointer_shortbuffer);
	}

	glVertexPointer_shortbuffer = calloc(length, sizeof(jshort));

	memcpy(glVertexPointer_shortbuffer, jshortArrayElements, length * sizeof(jshort)); // TODO: DPP: 190226T115900: Maybe don't need to copy, but just hold onto jshortArrayElements

	(*env)->ReleaseShortArrayElements(env, ptrJShortArray, jshortArrayElements, 0); // release resources

	glVertexPointer(size, GL_SHORT, stride, glVertexPointer_shortbuffer);
}
