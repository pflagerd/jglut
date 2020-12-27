#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glAlphaFunc__IF(JNIEnv *env, jobject object, jint funcJInt, jfloat refJFloat) {
    DPRINTF("glAlphaFunc(%d, %.8g%sf);\n", funcJInt, refJFloat, refJFloat == (int)refJFloat ? ".0" : "");
    glAlphaFunc(funcJInt, refJFloat);
}
