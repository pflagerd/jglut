#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex3f__FFF(JNIEnv *env, jobject object, jfloat x, jfloat y, jfloat z) {
    DPRINTF("glVertex3f(%.8g%sf, %.8g%sf, %.8g%sf);\n", x, x == (int)x ? ".0" : "", y, y == (int)y ? ".0" : "", z, z == (int)z ? ".0" : "");
    glVertex3f(x, y, z);
}
