#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos2f__DD(JNIEnv *env, jobject object, jdouble xJDouble, jdouble yJDouble) {
    DPRINTF("glRasterPos2f(%.17g%s, %.17g%s);\n", xJDouble, xJDouble == (int)xJDouble ? ".0" : "", yJDouble, yJDouble == (int)yJDouble ? ".0" : "");
    glRasterPos2f((float)xJDouble, (float)yJDouble);

}
