#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glViewport(JNIEnv* env, jobject object, jint x, jint y, jint width, jint height) {
	DPRINTF("glViewport(%d, %d, %d, %d)\n", x, y, width, height);
	glViewport(x, y, width, height);
}
