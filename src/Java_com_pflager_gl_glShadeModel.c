#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glShadeModel(JNIEnv* env, jobject object, jint mode) {
	DPRINTF("glShadeModel(0x%08x)\n", mode);
	glShadeModel(mode);
}
