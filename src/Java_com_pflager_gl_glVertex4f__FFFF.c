#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex4f__FFFF(JNIEnv *env, jobject object, jfloat xJFloat, jfloat yJFloat, jfloat zJFloat, jfloat wJFloat) {
    DPRINTF("glVertex4f(%.8g%sf, %.8g%sf, %.8g%sf, %.8g%sf);\n", xJFloat, xJFloat == (int)xJFloat ? ".0" : "", yJFloat, yJFloat == (int)yJFloat ? ".0" : "", zJFloat, zJFloat == (int)zJFloat ? ".0" : "", wJFloat, wJFloat == (int)wJFloat ? ".0" : "");
    glVertex4f(xJFloat, yJFloat, zJFloat, wJFloat);
}
