#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord3f__DDD(JNIEnv *env, jobject object, jdouble sJDouble, jdouble tJDouble, jdouble rJDouble) {
    DPRINTF("glTexCoord3f(%.17g%s, %.17g%s, %.17g%s);\n", sJDouble, sJDouble == (int)sJDouble ? ".0" : "", tJDouble, tJDouble == (int)tJDouble ? ".0" : "", rJDouble, rJDouble == (int)rJDouble ? ".0" : "");
    glTexCoord3f((float)sJDouble, (float)tJDouble, (float)rJDouble);

}
