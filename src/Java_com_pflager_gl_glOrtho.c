#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glOrtho(JNIEnv* env, jobject object, jdouble left, jdouble right, jdouble top, jdouble bottom, jdouble near_val, jdouble far_val) {
	DPRINTF("glOrtho(%.17g, %.17g, %.17g, %.17g, %.17g, %.17g)\n", left, right, top, bottom, near_val, far_val);
	glOrtho(left, right, top, bottom, near_val, far_val);
}
