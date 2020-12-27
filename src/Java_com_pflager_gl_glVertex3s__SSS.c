#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex3s__SSS(JNIEnv *env, jobject object, jshort xJShort, jshort yJShort, jshort zJShort) {
    DPRINTF("glVertex3s(%d, %d, %d);\n", xJShort, yJShort, zJShort);
    glVertex3s(xJShort, yJShort, zJShort);
}
