#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glStencilMask(JNIEnv *env, jobject object, jint maskJInt) {
    DPRINTF("glStencilMask(%d);\n", maskJInt);
    glStencilMask(maskJInt);

}
