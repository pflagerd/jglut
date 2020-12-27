#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glClearColor__DDDD(JNIEnv* env, jobject object, jdouble red, jdouble green, jdouble blue, jdouble alpha) {
	DPRINTF("glClearColor(%.17g, %.17g, %.17g, %.17g)\n", red, green, blue, alpha);

	glClearColor(red, green, blue, alpha);
}
