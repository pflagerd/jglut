#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEvalCoord2f(JNIEnv *env, jobject object, jdouble u, jdouble v) {
	Java_com_pflager_gl_glEvalCoord2d(env, object, u, v);
}
