#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex4d(JNIEnv *env, jobject object, jdouble xJDouble, jdouble yJDouble, jdouble zJDouble, jdouble wJDouble) {
    DPRINTF("glVertex4d(%.17g%s, %.17g%s, %.17g%s, %.17g%s);\n", xJDouble, xJDouble == (int)xJDouble ? ".0" : "", yJDouble, yJDouble == (int)yJDouble ? ".0" : "", zJDouble, zJDouble == (int)zJDouble ? ".0" : "", wJDouble, wJDouble == (int)wJDouble ? ".0" : "");
    glVertex4d(xJDouble, yJDouble, zJDouble, wJDouble);
}
