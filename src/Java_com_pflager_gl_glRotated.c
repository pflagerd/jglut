#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRotated(JNIEnv *env, jobject object, jdouble angle, jdouble x, jdouble y, jdouble z) {
    DPRINTF("glRotated(%.17g%s, %.17g%s, %.17g%s, %.17g%s);\n", angle, angle == (int)angle ? ".0" : "", x, x == (int)x ? ".0" : "", y, y == (int)y ? ".0" : "", z, z == (int)z ? ".0" : "");
    glRotated(angle, x, y, z);
}
