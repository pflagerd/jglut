#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPixelTransferf__ID(JNIEnv *env, jobject object, jint pnameJInt, jdouble paramJDouble) {
    DPRINTF("glPixelTransferf(%d, %.17g%s);\n", pnameJInt, paramJDouble, paramJDouble == (int)paramJDouble ? ".0" : "");
    glPixelTransferf(pnameJInt, (float)paramJDouble);

}
