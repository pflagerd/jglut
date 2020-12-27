#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glDepthMask__I(JNIEnv *env, jobject object, jint flagJInt) {
    DPRINTF("glDepthMask(%d);\n", flagJInt);
    glDepthMask(flagJInt);
}
