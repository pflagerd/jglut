#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRectd(JNIEnv *env, jobject object, jdouble arg0JDouble, jdouble arg1JDouble, jdouble arg2JDouble, jdouble arg3JDouble) {
    DPRINTF("glRectd(%.17g%s, %.17g%s, %.17g%s, %.17g%s);\n", arg0JDouble, arg0JDouble == (int)arg0JDouble ? ".0" : "", arg1JDouble, arg1JDouble == (int)arg1JDouble ? ".0" : "", arg2JDouble, arg2JDouble == (int)arg2JDouble ? ".0" : "", arg3JDouble, arg3JDouble == (int)arg3JDouble ? ".0" : "");
    glRectd(arg0JDouble, arg1JDouble, arg2JDouble, arg3JDouble);
}
