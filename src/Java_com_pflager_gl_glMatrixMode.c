#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glMatrixMode(JNIEnv* env, jobject object, jint mode) {
	DPRINTF("glMatrixMode(0x%08x)\n", mode);
	glMatrixMode(mode);
}
