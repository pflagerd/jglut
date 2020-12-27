#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glMaterialf__IID(JNIEnv *env, jobject object, jint faceJInt, jint pnameJInt, jdouble paramJDouble) {
    DPRINTF("glMaterialf(%d, %d, %.17g%s);\n", faceJInt, pnameJInt, paramJDouble, paramJDouble == (int)paramJDouble ? ".0" : "");
    glMaterialf(faceJInt, pnameJInt, (float)paramJDouble);
}
