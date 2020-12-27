#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glHint(JNIEnv *env, jobject object, jint targetJInt, jint modeJInt) {
    DPRINTF("glHint(%d, %d);\n", targetJInt, modeJInt);
    glHint(targetJInt, modeJInt);
}
