#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glClearAccum__DDDD(JNIEnv *env, jobject object, jdouble redJDouble, jdouble greenJDouble, jdouble blueJDouble, jdouble alphaJDouble) {
    DPRINTF("glClearAccum(%.17g%s, %.17g%s, %.17g%s, %.17g%s);\n", redJDouble, redJDouble == (int)redJDouble ? ".0" : "", greenJDouble, greenJDouble == (int)greenJDouble ? ".0" : "", blueJDouble, blueJDouble == (int)blueJDouble ? ".0" : "", alphaJDouble, alphaJDouble == (int)alphaJDouble ? ".0" : "");
    glClearAccum((float)redJDouble, (float)greenJDouble, (float)blueJDouble, (float)alphaJDouble);
}
