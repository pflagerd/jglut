#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT void JNICALL Java_com_pflager_glu_gluPerspective(JNIEnv *env, jobject object, jdouble fovy, jdouble aspect, jdouble zNear, jdouble zFar) {
    DPRINTF("gluPerspective(%.17g%s, %.17g%s, %.17g%s, %.17g%s);\n", fovy, fovy == (int)fovy ? ".0" : "", aspect, aspect == (int)aspect ? ".0" : "", zNear, zNear == (int)zNear ? ".0" : "", zFar, zFar == (int)zFar ? ".0" : "");
    gluPerspective(fovy, aspect, zNear, zFar);
}
