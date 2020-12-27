#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glDepthMask__Z(JNIEnv *env, jobject object, jboolean flagJBoolean) {
    DPRINTF("glDepthMask(%s);\n", flagJBoolean ? "true" : "false");
    glDepthMask(flagJBoolean);
}
