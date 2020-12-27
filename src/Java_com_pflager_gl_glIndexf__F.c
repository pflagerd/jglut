#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glIndexf__F(JNIEnv *env, jobject object, jfloat cJFloat) {
    DPRINTF("glIndexf(%.8g%sf);\n", cJFloat, cJFloat == (int)cJFloat ? ".0" : "");
    glIndexf(cJFloat);

}
