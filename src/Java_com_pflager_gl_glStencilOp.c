#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glStencilOp(JNIEnv *env, jobject object, jint failJInt, jint zfailJInt, jint zpassJInt) {
    DPRINTF("glStencilOp(%d, %d, %d);\n", failJInt, zfailJInt, zpassJInt);
    glStencilOp(failJInt, zfailJInt, zpassJInt);

}
