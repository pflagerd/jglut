#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glDepthRange(JNIEnv *env, jobject object, jdouble near_valJDouble, jdouble far_valJDouble) {
    DPRINTF("glDepthRange(%.17g%s, %.17g%s);\n", near_valJDouble, near_valJDouble == (int)near_valJDouble ? ".0" : "", far_valJDouble, far_valJDouble == (int)far_valJDouble ? ".0" : "");
    glDepthRange(near_valJDouble, far_valJDouble);
}
