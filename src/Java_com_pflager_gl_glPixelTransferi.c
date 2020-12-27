#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPixelTransferi(JNIEnv *env, jobject object, jint pnameJInt, jint paramJInt) {
    DPRINTF("glPixelTransferi(%d, %d);\n", pnameJInt, paramJInt);
    glPixelTransferi(pnameJInt, paramJInt);

}
