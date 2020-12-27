#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glLineStipple__II(JNIEnv *env, jobject object, jint factor, jint pattern) {
    DPRINTF("glLineStipple(%d, 0x%04x);\n", factor, pattern);
    glLineStipple(factor, pattern);
}
