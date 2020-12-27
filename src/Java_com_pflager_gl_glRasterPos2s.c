#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos2s(JNIEnv *env, jobject object, jshort xJShort, jshort yJShort) {
    DPRINTF("glRasterPos2s(%d, %d);\n", xJShort, yJShort);
    glRasterPos2s(xJShort, yJShort);

}
