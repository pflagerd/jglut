#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glBegin(JNIEnv* env, jobject object, jint mode) {
	DPRINTF("glBegin(%d)\n", mode);
	glBegin(mode);
}
