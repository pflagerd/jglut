#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex3f__DDD(JNIEnv* env, jobject object, jdouble x, jdouble y, jdouble z) {
	DPRINTF("glVertex3f(%.17g, %.17g, %.17g)\n", x, y, z);
	glVertex3d(x, y, z);
}
