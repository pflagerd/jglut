#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glFlush(JNIEnv* env, jobject object) {
	DPRINTF("glFlush()\n");
	glFlush();
}
