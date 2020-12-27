#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jint JNICALL Java_com_pflager_gl_glGetError(JNIEnv *env, jobject object) {
    DPRINTF("glGetError();\n");
    return glGetError();
}
