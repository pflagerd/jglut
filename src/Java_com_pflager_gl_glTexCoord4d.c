#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord4d(JNIEnv *env, jobject object, jdouble sJDouble, jdouble tJDouble, jdouble rJDouble, jdouble qJDouble) {
    DPRINTF("glTexCoord4d(%.17g%s, %.17g%s, %.17g%s, %.17g%s);\n", sJDouble, sJDouble == (int)sJDouble ? ".0" : "", tJDouble, tJDouble == (int)tJDouble ? ".0" : "", rJDouble, rJDouble == (int)rJDouble ? ".0" : "", qJDouble, qJDouble == (int)qJDouble ? ".0" : "");
    glTexCoord4d(sJDouble, tJDouble, rJDouble, qJDouble);

}
