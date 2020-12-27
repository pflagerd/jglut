#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glFrustum(JNIEnv *env, jobject object, jdouble left, jdouble right, jdouble bottom, jdouble top, jdouble near_val, jdouble far_val) {
    DPRINTF("glFrustum(%.17g%s, %.17g%s, %.17g%s, %.17g%s, %.17g%s, %.17g%s);\n", left, left == (int)left ? ".0" : "", right, right == (int)right ? ".0" : "", bottom, bottom == (int)bottom ? ".0" : "", top, top == (int)top ? ".0" : "", near_val, near_val == (int)near_val ? ".0" : "", far_val, far_val == (int)far_val ? ".0" : "");
    glFrustum(left, right, bottom, top, near_val, far_val);
}
