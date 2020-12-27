#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glMaterialf__IIF(JNIEnv *env, jobject object, jint faceJInt, jint pnameJInt, jfloat paramJFloat) {
    DPRINTF("glMaterialf(%d, %d, %.8g%sf);\n", faceJInt, pnameJInt, paramJFloat, paramJFloat == (int)paramJFloat ? ".0" : "");
    glMaterialf(faceJInt, pnameJInt, paramJFloat);
}
