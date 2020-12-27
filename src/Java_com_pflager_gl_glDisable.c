#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glDisable(JNIEnv *env, jobject object, jint cap) {
    DPRINTF("glDisable(0x%08x);\n", cap);
    glDisable(cap);
}
