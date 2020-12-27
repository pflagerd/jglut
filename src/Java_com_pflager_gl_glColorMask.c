#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColorMask(JNIEnv *env, jobject object, jint redJInt, jint greenJInt, jint blueJInt, jint alphaJInt) {
    DPRINTF("glColorMask(%d, %d, %d, %d);\n", redJInt, greenJInt, blueJInt, alphaJInt);
    glColorMask(redJInt, greenJInt, blueJInt, alphaJInt);
}
