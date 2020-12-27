#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPixelZoom__DD(JNIEnv *env, jobject object, jdouble xfactorJDouble, jdouble yfactorJDouble) {
    DPRINTF("glPixelZoom(%.17g%s, %.17g%s);\n", xfactorJDouble, xfactorJDouble == (int)xfactorJDouble ? ".0" : "", yfactorJDouble, yfactorJDouble == (int)yfactorJDouble ? ".0" : "");
    glPixelZoom((float)xfactorJDouble, (float)yfactorJDouble);

}
