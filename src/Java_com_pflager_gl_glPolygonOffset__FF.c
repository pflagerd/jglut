#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPolygonOffset__FF(JNIEnv *env, jobject object, jfloat factorJFloat, jfloat unitsJFloat) {
    DPRINTF("glPolygonOffset(%.8g%sf, %.8g%sf);\n", factorJFloat, factorJFloat == (int)factorJFloat ? ".0" : "", unitsJFloat, unitsJFloat == (int)unitsJFloat ? ".0" : "");
    glPolygonOffset(factorJFloat, unitsJFloat);
}
