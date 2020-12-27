#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPushAttrib(JNIEnv *env, jobject object, jint maskJInt) {
    DPRINTF("glPushAttrib(%d);\n", maskJInt);
    glPushAttrib(maskJInt);
}
