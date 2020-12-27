#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glClearIndex__D(JNIEnv *env, jobject object, jdouble cJDouble) {
    DPRINTF("glClearIndex(%.17g%s);\n", cJDouble, cJDouble == (int)cJDouble ? ".0" : "");
    glClearIndex((float)cJDouble);
}
