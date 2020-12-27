#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor4f__FFFF(JNIEnv *env, jobject object, jfloat redJFloat, jfloat greenJFloat, jfloat blueJFloat, jfloat alphaJFloat) {
    DPRINTF("glColor4f(%.8g%sf, %.8g%sf, %.8g%sf, %.8g%sf);\n", redJFloat, redJFloat == (int)redJFloat ? ".0" : "", greenJFloat, greenJFloat == (int)greenJFloat ? ".0" : "", blueJFloat, blueJFloat == (int)blueJFloat ? ".0" : "", alphaJFloat, alphaJFloat == (int)alphaJFloat ? ".0" : "");
    glColor4f(redJFloat, greenJFloat, blueJFloat, alphaJFloat);

}
