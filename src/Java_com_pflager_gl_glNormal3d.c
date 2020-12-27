#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glNormal3d(JNIEnv *env, jobject object, jdouble nxJDouble, jdouble nyJDouble, jdouble nzJDouble) {
    DPRINTF("glNormal3d(%.17g%s, %.17g%s, %.17g%s);\n", nxJDouble, nxJDouble == (int)nxJDouble ? ".0" : "", nyJDouble, nyJDouble == (int)nyJDouble ? ".0" : "", nzJDouble, nzJDouble == (int)nzJDouble ? ".0" : "");
    glNormal3d(nxJDouble, nyJDouble, nzJDouble);

}
