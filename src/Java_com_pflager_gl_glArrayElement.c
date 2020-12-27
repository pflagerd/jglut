#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glArrayElement(JNIEnv *env, jobject object, jint i) {
    DPRINTF("glArrayElement(%d);\n", i);
    glArrayElement(i);
}
