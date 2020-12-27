#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

void* glColorPointer_shortbuffer; // Initially zero.
								// Set each time this function is called.
								// If non-zero when the function is called, it is freed.
								// Not sure if at_exit() will work with java.

JNIEXPORT void JNICALL Java_com_pflager_gl_glColorPointer__III_3S(JNIEnv *env, jobject object, jint size, jint type, jint stride, jshortArray ptrJShortArray) {
    DPRINTF("glColorPointer(%d, %d, %d, 0x%p);\n", size, type, stride, ptrJShortArray);
	if (ptrJShortArray == NULL) {
		return;
	}

	jsize length = (*env)->GetArrayLength(env, ptrJShortArray);
	if (length == 0) {
		return;
	}

	jshort *jshortArrayElements = (*env)->GetShortArrayElements(env, ptrJShortArray, NULL);

	if (glColorPointer_shortbuffer != 0) {
		DPRINTF("Freeing glColorPointer_shortbuffer before re-calloc()ing it.");
		free(glColorPointer_shortbuffer);
	}

	glColorPointer_shortbuffer = calloc(length, sizeof(jshort));

	memcpy(glColorPointer_shortbuffer, jshortArrayElements, length * sizeof(jshort));

	(*env)->ReleaseShortArrayElements(env, ptrJShortArray, jshortArrayElements, 0); // release resources

    glColorPointer(size, GL_SHORT, stride, glColorPointer_shortbuffer);
}
