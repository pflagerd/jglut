#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glAlphaFunc__ID(JNIEnv *env, jobject object, jint funcJInt, jdouble refJDouble) {
    DPRINTF("glAlphaFunc(%d, %.17g%s);\n", funcJInt, refJDouble, refJDouble == (int)refJDouble ? ".0" : "");
    glAlphaFunc(funcJInt, (float)refJDouble);
}
