#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glNormal3f__FFF(JNIEnv *env, jobject object, jfloat nxJFloat, jfloat nyJFloat, jfloat nzJFloat) {
    DPRINTF("glNormal3f(%.8g%sf, %.8g%sf, %.8g%sf);\n", nxJFloat, nxJFloat == (int)nxJFloat ? ".0" : "", nyJFloat, nyJFloat == (int)nyJFloat ? ".0" : "", nzJFloat, nzJFloat == (int)nzJFloat ? ".0" : "");
    glNormal3f(nxJFloat, nyJFloat, nzJFloat);

}
