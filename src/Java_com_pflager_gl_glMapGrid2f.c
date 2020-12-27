#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glMapGrid2f(JNIEnv *env, jobject object, jint un, jdouble u1, jdouble u2, jint vn, jdouble v1, jdouble v2) {
	Java_com_pflager_gl_glMapGrid2d(env, object, un, u1, u2, vn, v1, v2);
}
