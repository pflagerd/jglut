#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glIndexd(JNIEnv *env, jobject object, jdouble cJDouble) {
    DPRINTF("glIndexd(%.17g%s);\n", cJDouble, cJDouble == (int)cJDouble ? ".0" : "");
    glIndexd(cJDouble);

}
