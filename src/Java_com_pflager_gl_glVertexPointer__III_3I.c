#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

void* glVertexPointer_intbuffer;// Initially zero.
								// Set each time this function is called.
								// If non-zero when the function is called, it is freed.
								// Not sure if at_exit() will work with java.

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertexPointer__III_3I(JNIEnv *env, jobject object, jint size, jint type, jint stride, jintArray ptrJIntArray) {
	DPRINTF("glVertexPointer(%d, %d, %d, %p);\n", size, type, stride, ptrJIntArray);
	if (ptrJIntArray == NULL) {
		return;
	}

	jsize length = (*env)->GetArrayLength(env, ptrJIntArray);
	if (length == 0) {
		return;
	}

	jint *jintArrayElements = (*env)->GetIntArrayElements(env, ptrJIntArray, NULL);

	if (glVertexPointer_intbuffer != 0) {
		DPRINTF("Freeing glVertexPointer_intbuffer before re-calloc()ing it.");
		free(glVertexPointer_intbuffer);
	}

	glVertexPointer_intbuffer = calloc(length, sizeof(jint));

	memcpy(glVertexPointer_intbuffer, jintArrayElements, length * sizeof(jint)); // TODO: DPP: 190226T115900: Maybe don't need to copy, but just hold onto jintArrayElements

	(*env)->ReleaseIntArrayElements(env, ptrJIntArray, jintArrayElements, 0); // release resources

	glVertexPointer(size, GL_INT, stride, glVertexPointer_intbuffer);
}
