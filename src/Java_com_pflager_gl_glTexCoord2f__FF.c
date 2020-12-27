#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord2f__FF(JNIEnv *env, jobject object, jfloat sJFloat, jfloat tJFloat) {
    DPRINTF("glTexCoord2f(%.8g%sf, %.8g%sf);\n", sJFloat, sJFloat == (int)sJFloat ? ".0" : "", tJFloat, tJFloat == (int)tJFloat ? ".0" : "");
    glTexCoord2f(sJFloat, tJFloat);

}
