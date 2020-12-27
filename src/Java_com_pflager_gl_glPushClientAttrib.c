#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPushClientAttrib(JNIEnv *env, jobject object, jint maskJInt) {
    DPRINTF("glPushClientAttrib(%d);\n", maskJInt);
    glPushClientAttrib(maskJInt);
}
