#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord1f(JNIEnv *env, jobject object, jfloat sJFloat) {
    DPRINTF("glTexCoord1f(%.8g%sf);\n", sJFloat, sJFloat == (int)sJFloat ? ".0" : "");
    glTexCoord1f(sJFloat);

}
