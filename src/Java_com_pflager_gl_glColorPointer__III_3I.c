#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

void* glColorPointer_intbuffer; // Initially zero.
								// Set each time this function is called.
								// If non-zero when the function is called, it is freed.
								// Not sure if at_exit() will work with java.

JNIEXPORT void JNICALL Java_com_pflager_gl_glColorPointer__III_3I(JNIEnv *env, jobject object, jint size, jint type, jint stride, jintArray ptrJIntArray) {
    DPRINTF("glColorPointer(%d, %d, %d, %p);\n", size, type, stride, ptrJIntArray);
	if (ptrJIntArray == NULL) {
		return;
	}

	jsize length = (*env)->GetArrayLength(env, ptrJIntArray);
	if (length == 0) {
		return;
	}

	jint *jintArrayElements = (*env)->GetIntArrayElements(env, ptrJIntArray, NULL);

	if (glColorPointer_intbuffer != 0) {
		DPRINTF("Freeing glColorPointer_intbuffer before re-calloc()ing it.");
		free(glColorPointer_intbuffer);
	}

	glColorPointer_intbuffer = calloc(length, sizeof(jint));

	memcpy(glColorPointer_intbuffer, jintArrayElements, length * sizeof(jint));

	(*env)->ReleaseIntArrayElements(env, ptrJIntArray, jintArrayElements, 0); // release resources

    glColorPointer(size, GL_INT, stride, glColorPointer_intbuffer);
}
