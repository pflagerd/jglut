#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glFogf__IF(JNIEnv *env, jobject object, jint pnameJInt, jfloat paramJFloat) {
    DPRINTF("glFogf(%d, %.8g%sf);\n", pnameJInt, paramJFloat, paramJFloat == (int)paramJFloat ? ".0" : "");
    glFogf(pnameJInt, paramJFloat);

}
