#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos3f__DDD(JNIEnv *env, jobject object, jdouble xJDouble, jdouble yJDouble, jdouble zJDouble) {
    DPRINTF("glRasterPos3f(%.17g%s, %.17g%s, %.17g%s);\n", xJDouble, xJDouble == (int)xJDouble ? ".0" : "", yJDouble, yJDouble == (int)yJDouble ? ".0" : "", zJDouble, zJDouble == (int)zJDouble ? ".0" : "");
    glRasterPos3f((float)xJDouble, (float)yJDouble, (float)zJDouble);

}
