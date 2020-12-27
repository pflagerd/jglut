#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor3f__FFF(JNIEnv *env, jobject object, jfloat red, jfloat green, jfloat blue) {
    DPRINTF("glColor3f(%.8g%sf, %.8g%sf, %.8g%sf);\n", red, red == (int)red ? ".0" : "", green, green == (int)green ? ".0" : "", blue, blue == (int)blue ? ".0" : "");
    glColor3f(red, green, blue);
}
