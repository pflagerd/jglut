#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glScaled(JNIEnv *env, jobject object, jdouble x, jdouble y, jdouble z) {
    DPRINTF("glScaled(%.17g%s, %.17g%s, %.17g%s);\n", x, x == (int)x ? ".0" : "", y, y == (int)y ? ".0" : "", z, z == (int)z ? ".0" : "");
    glScaled(x, y, z);
}
