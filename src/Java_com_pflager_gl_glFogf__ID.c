#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glFogf__ID(JNIEnv *env, jobject object, jint pnameJInt, jdouble paramJDouble) {
    DPRINTF("glFogf(%d, %.17g%s);\n", pnameJInt, paramJDouble, paramJDouble == (int)paramJDouble ? ".0" : "");
    glFogf(pnameJInt, (float)paramJDouble);

}
