#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glClearColor__FFFF(JNIEnv *env, jobject object, jfloat red, jfloat green, jfloat blue, jfloat alpha) {
    DPRINTF("glClearColor(%.8g%sf, %.8g%sf, %.8g%sf, %.8g%sf);\n", red, red == (int)red ? ".0" : "", green, green == (int)green ? ".0" : "", blue, blue == (int)blue ? ".0" : "", alpha, alpha == (int)alpha ? ".0" : "");
    glClearColor(red, green, blue, alpha);
}
