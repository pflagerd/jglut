#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex2d(JNIEnv *env, jobject object, jdouble xJDouble, jdouble yJDouble) {
    DPRINTF("glVertex2d(%.17g%s, %.17g%s);\n", xJDouble, xJDouble == (int)xJDouble ? ".0" : "", yJDouble, yJDouble == (int)yJDouble ? ".0" : "");
    glVertex2d(xJDouble, yJDouble);
}
