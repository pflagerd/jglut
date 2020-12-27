#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glDepthFunc(JNIEnv *env, jobject object, jint funcJInt) {
    DPRINTF("glDepthFunc(%d);\n", funcJInt);
    glDepthFunc(funcJInt);
}
