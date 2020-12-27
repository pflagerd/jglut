#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_glu.h"

JNIEXPORT void JNICALL Java_com_pflager_glu_gluOrtho2D(JNIEnv *env, jobject object, jdouble left, jdouble right, jdouble bottom, jdouble top) {
    DPRINTF("gluOrtho2D(%.17g%s, %.17g%s, %.17g%s, %.17g%s);\n", left, left == (int)left ? ".0" : "", right, right == (int)right ? ".0" : "", bottom, bottom == (int)bottom ? ".0" : "", top, top == (int)top ? ".0" : "");
    gluOrtho2D(left, right, bottom, top);
}
