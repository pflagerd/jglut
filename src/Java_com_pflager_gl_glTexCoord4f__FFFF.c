#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord4f__FFFF(JNIEnv *env, jobject object, jfloat sJFloat, jfloat tJFloat, jfloat rJFloat, jfloat qJFloat) {
    DPRINTF("glTexCoord4f(%.8g%sf, %.8g%sf, %.8g%sf, %.8g%sf);\n", sJFloat, sJFloat == (int)sJFloat ? ".0" : "", tJFloat, tJFloat == (int)tJFloat ? ".0" : "", rJFloat, rJFloat == (int)rJFloat ? ".0" : "", qJFloat, qJFloat == (int)qJFloat ? ".0" : "");
    glTexCoord4f(sJFloat, tJFloat, rJFloat, qJFloat);

}
