#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos2f__FF(JNIEnv *env, jobject object, jfloat xJFloat, jfloat yJFloat) {
    DPRINTF("glRasterPos2f(%.8g%sf, %.8g%sf);\n", xJFloat, xJFloat == (int)xJFloat ? ".0" : "", yJFloat, yJFloat == (int)yJFloat ? ".0" : "");
    glRasterPos2f(xJFloat, yJFloat);

}
