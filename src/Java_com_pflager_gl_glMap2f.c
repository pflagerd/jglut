#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glMap2f(JNIEnv *env, jobject object, jint target, jdouble u1, jdouble u2, jint ustride, jint uorder, jdouble v1, jdouble v2, jint vstride, jint vorder, jobjectArray points) {
	Java_com_pflager_gl_glMap2d(env, object, target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
