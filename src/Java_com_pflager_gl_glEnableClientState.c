#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEnableClientState(JNIEnv *env, jobject object, jint cap) {
    DPRINTF("glEnableClientState(0x%08x);\n", cap);
    glEnableClientState(cap);
}
