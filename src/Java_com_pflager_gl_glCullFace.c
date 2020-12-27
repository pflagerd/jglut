#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glCullFace(JNIEnv *env, jobject object, jint modeJInt) {
    DPRINTF("glCullFace(%d);\n", modeJInt);
    glCullFace(modeJInt);
}
