#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glDrawArrays(JNIEnv *env, jobject object, jint mode, jint first, jint count) {
    DPRINTF("glDrawArrays(%d, %d, %d);\n", mode, first, count);
    glDrawArrays(mode, first, count);
}
