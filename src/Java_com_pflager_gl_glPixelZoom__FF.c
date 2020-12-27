#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPixelZoom__FF(JNIEnv *env, jobject object, jfloat xfactorJFloat, jfloat yfactorJFloat) {
    DPRINTF("glPixelZoom(%.8g%sf, %.8g%sf);\n", xfactorJFloat, xfactorJFloat == (int)xfactorJFloat ? ".0" : "", yfactorJFloat, yfactorJFloat == (int)yfactorJFloat ? ".0" : "");
    glPixelZoom(xfactorJFloat, yfactorJFloat);

}
