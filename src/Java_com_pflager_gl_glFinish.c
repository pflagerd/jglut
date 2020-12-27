#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glFinish(JNIEnv *env, jobject object) {
    DPRINTF("glFinish();\n");
    glFinish();
}
