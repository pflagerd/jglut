#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEvalCoord1f(JNIEnv *env, jobject object, jdouble u) {
	Java_com_pflager_gl_glEvalCoord1d(env, object, u);
}
