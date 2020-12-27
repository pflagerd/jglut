#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glBindTexture(JNIEnv *env, jobject object, jint targetJInt, jint textureJInt) {
    DPRINTF("glBindTexture(%d, %d);\n", targetJInt, textureJInt);
    glBindTexture(targetJInt, textureJInt);
}
