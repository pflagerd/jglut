#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glLightf__IIF(JNIEnv *env, jobject object, jint lightJInt, jint pnameJInt, jfloat paramJFloat) {
    DPRINTF("glLightf(%d, %d, %.8g%sf);\n", lightJInt, pnameJInt, paramJFloat, paramJFloat == (int)paramJFloat ? ".0" : "");
    glLightf(lightJInt, pnameJInt, paramJFloat);
}
