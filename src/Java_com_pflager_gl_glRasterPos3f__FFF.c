#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos3f__FFF(JNIEnv *env, jobject object, jfloat xJFloat, jfloat yJFloat, jfloat zJFloat) {
    DPRINTF("glRasterPos3f(%.8g%sf, %.8g%sf, %.8g%sf);\n", xJFloat, xJFloat == (int)xJFloat ? ".0" : "", yJFloat, yJFloat == (int)yJFloat ? ".0" : "", zJFloat, zJFloat == (int)zJFloat ? ".0" : "");
    glRasterPos3f(xJFloat, yJFloat, zJFloat);

}
