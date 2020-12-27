#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos3s(JNIEnv *env, jobject object, jshort xJShort, jshort yJShort, jshort zJShort) {
    DPRINTF("glRasterPos3s(%d, %d, %d);\n", xJShort, yJShort, zJShort);
    glRasterPos3s(xJShort, yJShort, zJShort);

}
