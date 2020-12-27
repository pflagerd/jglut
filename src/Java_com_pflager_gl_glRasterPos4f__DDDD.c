#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos4f__DDDD(JNIEnv *env, jobject object, jdouble xJDouble, jdouble yJDouble, jdouble zJDouble, jdouble wJDouble) {
    DPRINTF("glRasterPos4f(%.17g%s, %.17g%s, %.17g%s, %.17g%s);\n", xJDouble, xJDouble == (int)xJDouble ? ".0" : "", yJDouble, yJDouble == (int)yJDouble ? ".0" : "", zJDouble, zJDouble == (int)zJDouble ? ".0" : "", wJDouble, wJDouble == (int)wJDouble ? ".0" : "");
    glRasterPos4f((float)xJDouble, (float)yJDouble, (float)zJDouble, (float)wJDouble);

}
