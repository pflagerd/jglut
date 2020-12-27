#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glFrontFace(JNIEnv *env, jobject object, jint modeJInt) {
    DPRINTF("glFrontFace(%d);\n", modeJInt);
    glFrontFace(modeJInt);
}
