#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPointSize(JNIEnv *env, jobject object, jdouble size) {
    DPRINTF("glPointSize(%.9g%s);\n", size, size == (int)size ? ".0" : "");
    glPointSize((float)size);
}
