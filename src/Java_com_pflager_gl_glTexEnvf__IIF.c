#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexEnvf__IIF(JNIEnv *env, jobject object, jint targetJInt, jint pnameJInt, jfloat paramJFloat) {
    DPRINTF("glTexEnvf(%d, %d, %.8g%sf);\n", targetJInt, pnameJInt, paramJFloat, paramJFloat == (int)paramJFloat ? ".0" : "");
    glTexEnvf(targetJInt, pnameJInt, paramJFloat);

}
