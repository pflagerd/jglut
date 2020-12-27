#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPolygonOffset__DD(JNIEnv *env, jobject object, jdouble factorJDouble, jdouble unitsJDouble) {
    DPRINTF("glPolygonOffset(%.17g%s, %.17g%s);\n", factorJDouble, factorJDouble == (int)factorJDouble ? ".0" : "", unitsJDouble, unitsJDouble == (int)unitsJDouble ? ".0" : "");
    glPolygonOffset((float)factorJDouble, (float)unitsJDouble);
}
