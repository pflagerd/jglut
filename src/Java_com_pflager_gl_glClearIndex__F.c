#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glClearIndex__F(JNIEnv *env, jobject object, jfloat cJFloat) {
    DPRINTF("glClearIndex(%.8g%sf);\n", cJFloat, cJFloat == (int)cJFloat ? ".0" : "");
    glClearIndex(cJFloat);
}
