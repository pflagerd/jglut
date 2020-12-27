#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex2f__FF(JNIEnv *env, jobject object, jfloat x, jfloat y) {
    DPRINTF("glVertex2f(%.9g%sf, %.9g%sf);\n", x, x == (int)x ? ".0" : "", y, y == (int)y ? ".0" : "");
    glVertex2f(x, y);
}
