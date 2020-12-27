#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glLightf__IID(JNIEnv *env, jobject object, jint lightJInt, jint pnameJInt, jdouble paramJDouble) {
    DPRINTF("glLightf(%d, %d, %.17g%s);\n", lightJInt, pnameJInt, paramJDouble, paramJDouble == (int)paramJDouble ? ".0" : "");
    glLightf(lightJInt, pnameJInt, (float)paramJDouble);
}
