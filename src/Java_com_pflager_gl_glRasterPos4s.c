#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos4s(JNIEnv *env, jobject object, jshort xJShort, jshort yJShort, jshort zJShort, jshort wJShort) {
    DPRINTF("glRasterPos4s(%d, %d, %d, %d);\n", xJShort, yJShort, zJShort, wJShort);
    glRasterPos4s(xJShort, yJShort, zJShort, wJShort);

}
