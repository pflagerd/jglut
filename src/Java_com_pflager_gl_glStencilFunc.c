#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glStencilFunc(JNIEnv *env, jobject object, jint funcJInt, jint refJInt, jint maskJInt) {
    DPRINTF("glStencilFunc(%d, %d, %d);\n", funcJInt, refJInt, maskJInt);
    glStencilFunc(funcJInt, refJInt, maskJInt);

}
