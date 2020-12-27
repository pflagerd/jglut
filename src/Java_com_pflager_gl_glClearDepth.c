#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glClearDepth(JNIEnv *env, jobject object, jdouble depthJDouble) {
    DPRINTF("glClearDepth(%.17g%s);\n", depthJDouble, depthJDouble == (int)depthJDouble ? ".0" : "");
    glClearDepth(depthJDouble);
}
