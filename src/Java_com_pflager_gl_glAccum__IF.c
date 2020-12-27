#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glAccum__IF(JNIEnv *env, jobject object, jint opJInt, jfloat valueJFloat) {
    DPRINTF("glAccum(%d, %.8g%sf);\n", opJInt, valueJFloat, valueJFloat == (int)valueJFloat ? ".0" : "");
    glAccum(opJInt, valueJFloat);
}
