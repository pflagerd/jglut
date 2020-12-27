#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glListBase(JNIEnv *env, jobject object, jint baseJInt) {
    DPRINTF("glListBase(%d);\n", baseJInt);
    glListBase(baseJInt);
}
