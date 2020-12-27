#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor3d(JNIEnv *env, jobject object, jdouble red, jdouble green, jdouble blue) {
    DPRINTF("glColor3d(%.17g%s, %.17g%s, %.17g%s);\n", red, red == (int)red ? ".0" : "", green, green == (int)green ? ".0" : "", blue, blue == (int)blue ? ".0" : "");
    glColor3d(red, green, blue);
}
