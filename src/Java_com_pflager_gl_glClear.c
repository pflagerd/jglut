#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glClear(JNIEnv* env, jobject object, jint mask) {
	DPRINTF("glClear(0x%08x)\n", mask);
	glClear(mask);
}
