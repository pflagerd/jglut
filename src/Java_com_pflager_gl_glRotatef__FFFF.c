#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRotatef__FFFF(JNIEnv* env, jobject object, jfloat angle, jfloat x, jfloat y, jfloat z) {
	DPRINTF("glRotatef(%.9ff, %.9ff, %.9ff, %.9ff)\n", angle, x, y, z);
	glRotatef(angle, x, y, z);
}
