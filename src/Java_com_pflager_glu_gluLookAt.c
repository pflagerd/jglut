#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT void JNICALL Java_com_pflager_glu_gluLookAt(JNIEnv *env, jobject object, jdouble eyeX, jdouble eyeY, jdouble eyeZ, jdouble centerX, jdouble centerY, jdouble centerZ, jdouble upX, jdouble upY, jdouble upZ) {
    DPRINTF("gluLookAt(%.17g%s, %.17g%s, %.17g%s, %.17g%s, %.17g%s, %.17g%s, %.17g%s, %.17g%s, %.17g%s);\n", eyeX, eyeX == (int)eyeX ? ".0" : "", eyeY, eyeY == (int)eyeY ? ".0" : "", eyeZ, eyeZ == (int)eyeZ ? ".0" : "", centerX, centerX == (int)centerX ? ".0" : "", centerY, centerY == (int)centerY ? ".0" : "", centerZ, centerZ == (int)centerZ ? ".0" : "", upX, upX == (int)upX ? ".0" : "", upY, upY == (int)upY ? ".0" : "", upZ, upZ == (int)upZ ? ".0" : "");
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
}
