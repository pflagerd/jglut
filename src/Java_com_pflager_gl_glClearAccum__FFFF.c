#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glClearAccum__FFFF(JNIEnv *env, jobject object, jfloat redJFloat, jfloat greenJFloat, jfloat blueJFloat, jfloat alphaJFloat) {
    DPRINTF("glClearAccum(%.8g%sf, %.8g%sf, %.8g%sf, %.8g%sf);\n", redJFloat, redJFloat == (int)redJFloat ? ".0" : "", greenJFloat, greenJFloat == (int)greenJFloat ? ".0" : "", blueJFloat, blueJFloat == (int)blueJFloat ? ".0" : "", alphaJFloat, alphaJFloat == (int)alphaJFloat ? ".0" : "");
    glClearAccum(redJFloat, greenJFloat, blueJFloat, alphaJFloat);
}
