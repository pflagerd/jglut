#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glLogicOp(JNIEnv *env, jobject object, jint opcodeJInt) {
    DPRINTF("glLogicOp(%d);\n", opcodeJInt);
    glLogicOp(opcodeJInt);
}
