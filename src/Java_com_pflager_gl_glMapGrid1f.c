#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glMapGrid1f(JNIEnv *env, jobject object, jint unJInt, jdouble u1JDouble, jdouble u2JDouble) {
    DPRINTF("glMapGrid1f(%d, %.17g%s, %.17g%s);\n", unJInt, u1JDouble, u1JDouble == (int)u1JDouble ? ".0" : "", u2JDouble, u2JDouble == (int)u2JDouble ? ".0" : "");
    glMapGrid1f(unJInt, (float)u1JDouble, (float)u2JDouble);

}
