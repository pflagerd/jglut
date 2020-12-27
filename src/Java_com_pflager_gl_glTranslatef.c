#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTranslatef(JNIEnv *env, jobject object, jdouble x, jdouble y, jdouble z) {
    DPRINTF("glTranslatef(%.8g%sf, %.8g%sf, %.8g%sf);\n", x, x == (int)x ? ".0" : "", y, y == (int)y ? ".0" : "", z, z == (int)z ? ".0" : "");
    glTranslatef((GLfloat)x, (GLfloat)y, (GLfloat)z);
}
