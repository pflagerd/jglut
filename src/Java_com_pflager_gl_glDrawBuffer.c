#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glDrawBuffer(JNIEnv *env, jobject object, jint modeJInt) {
    DPRINTF("glDrawBuffer(%d);\n", modeJInt);
    glDrawBuffer(modeJInt);
}
