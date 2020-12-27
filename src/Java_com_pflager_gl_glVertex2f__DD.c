#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex2f__DD(JNIEnv *env, jobject object, jdouble x, jdouble y) {
    DPRINTF("glVertex2f(%.9g%s, %.9g%s);\n", x, x == (int)x ? ".0" : "", y, y == (int)y ? ".0" : "");
    glVertex2d(x, y);
}
