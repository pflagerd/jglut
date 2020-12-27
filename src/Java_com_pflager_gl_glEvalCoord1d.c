#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEvalCoord1d(JNIEnv *env, jobject object, jdouble u) {
    DPRINTF("glEvalCoord1d(%.17g%s);\n", u, u == (int)u ? ".0" : "");
    glEvalCoord1d(u);
}
