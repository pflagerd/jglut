#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex4s__SSSS(JNIEnv *env, jobject object, jshort xJShort, jshort yJShort, jshort zJShort, jshort wJShort) {
    DPRINTF("glVertex4s(%d, %d, %d, %d);\n", xJShort, yJShort, zJShort, wJShort);
    glVertex4s(xJShort, yJShort, zJShort, wJShort);
}
