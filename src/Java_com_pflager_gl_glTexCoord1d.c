#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord1d(JNIEnv *env, jobject object, jdouble sJDouble) {
    DPRINTF("glTexCoord1d(%.17g%s);\n", sJDouble, sJDouble == (int)sJDouble ? ".0" : "");
    glTexCoord1d(sJDouble);

}
