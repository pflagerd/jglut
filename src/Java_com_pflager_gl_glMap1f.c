#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glMap1f(JNIEnv *env, jobject object, jint target, jdouble u1, jdouble u2, jint stride, jint order, jobjectArray points) {
	Java_com_pflager_gl_glMap1d(env, object, target, u1, u2, stride, order, points);
}
