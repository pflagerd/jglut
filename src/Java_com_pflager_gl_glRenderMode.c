#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jint JNICALL Java_com_pflager_gl_glRenderMode(JNIEnv *env, jobject object, jint modeJInt) {
    DPRINTF("glRenderMode(%d);\n", modeJInt);
    return glRenderMode(modeJInt);
}
