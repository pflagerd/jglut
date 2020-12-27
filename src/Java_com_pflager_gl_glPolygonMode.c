#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPolygonMode(JNIEnv *env, jobject object, jint face, jint mode) {
    DPRINTF("glPolygonMode(0x%08x, 0x%08x);\n", face, mode);
    glPolygonMode(face, mode);
}
