#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexEnvf__IID(JNIEnv *env, jobject object, jint targetJInt, jint pnameJInt, jdouble paramJDouble) {
    DPRINTF("glTexEnvf(%d, %d, %.17g%s);\n", targetJInt, pnameJInt, paramJDouble, paramJDouble == (int)paramJDouble ? ".0" : "");
    glTexEnvf(targetJInt, pnameJInt, (float)paramJDouble);

}
