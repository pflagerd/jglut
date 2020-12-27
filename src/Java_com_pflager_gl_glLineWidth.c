#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glLineWidth(JNIEnv *env, jobject object, jdouble width) {
    DPRINTF("glLineWidth(%.17g%s);\n", width, width == (int)width ? ".0" : "");
    glLineWidth(width);
}
