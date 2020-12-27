#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord3f__FFF(JNIEnv *env, jobject object, jfloat sJFloat, jfloat tJFloat, jfloat rJFloat) {
    DPRINTF("glTexCoord3f(%.8g%sf, %.8g%sf, %.8g%sf);\n", sJFloat, sJFloat == (int)sJFloat ? ".0" : "", tJFloat, tJFloat == (int)tJFloat ? ".0" : "", rJFloat, rJFloat == (int)rJFloat ? ".0" : "");
    glTexCoord3f(sJFloat, tJFloat, rJFloat);

}
