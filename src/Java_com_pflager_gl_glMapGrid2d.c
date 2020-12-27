#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glMapGrid2d(JNIEnv *env, jobject object, jint un, jdouble u1, jdouble u2, jint vn, jdouble v1, jdouble v2) {
    DPRINTF("glMapGrid2d(%d, %.17g%s, %.17g%s, %d, %.17g%s, %.17g%s);\n", un, u1, u1 == (int)u1 ? ".0" : "", u2, u2 == (int)u2 ? ".0" : "", vn, v1, v1 == (int)v1 ? ".0" : "", v2, v2 == (int)v2 ? ".0" : "");
    glMapGrid2d(un, u1, u2, vn, v1, v2);
}
