#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexGend(JNIEnv *env, jobject object, jint coordJInt, jint pnameJInt, jdouble paramJDouble) {
    DPRINTF("glTexGend(%d, %d, %.17g%s);\n", coordJInt, pnameJInt, paramJDouble, paramJDouble == (int)paramJDouble ? ".0" : "");
    glTexGend(coordJInt, pnameJInt, paramJDouble);

}
