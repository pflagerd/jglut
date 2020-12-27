#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord2d(JNIEnv *env, jobject object, jdouble sJDouble, jdouble tJDouble) {
    DPRINTF("glTexCoord2d(%.17g%s, %.17g%s);\n", sJDouble, sJDouble == (int)sJDouble ? ".0" : "", tJDouble, tJDouble == (int)tJDouble ? ".0" : "");
    glTexCoord2d(sJDouble, tJDouble);

}
