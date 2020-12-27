#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glIndexf__D(JNIEnv *env, jobject object, jdouble cJDouble) {
    DPRINTF("glIndexf(%.17g%s);\n", cJDouble, cJDouble == (int)cJDouble ? ".0" : "");
    glIndexf((float)cJDouble);

}
