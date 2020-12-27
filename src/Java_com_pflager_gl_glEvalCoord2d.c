#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEvalCoord2d(JNIEnv *env, jobject object, jdouble u, jdouble v) {
    DPRINTF("glEvalCoord2d(%.17g%s, %.17g%s);\n", u, u == (int)u ? ".0" : "", v, v == (int)v ? ".0" : "");
    glEvalCoord2d(u, v);
}
