#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glAccum__ID(JNIEnv *env, jobject object, jint opJInt, jdouble valueJDouble) {
    DPRINTF("glAccum(%d, %.17g%s);\n", opJInt, valueJDouble, valueJDouble == (int)valueJDouble ? ".0" : "");
    glAccum(opJInt, (float)valueJDouble);
}
