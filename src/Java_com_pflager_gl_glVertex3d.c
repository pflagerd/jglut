#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex3d(JNIEnv *env, jobject object, jdouble x, jdouble y, jdouble z) {
    DPRINTF("glVertex3d(%.17g%s, %.17g%s, %.17g%s);\n", x, x == (int)x ? ".0" : "", y, y == (int)y ? ".0" : "", z, z == (int)z ? ".0" : "");
    glVertex3d(x, y, z);
}
