#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex2s__SS(JNIEnv *env, jobject object, jshort xJShort, jshort yJShort) {
    DPRINTF("glVertex2s(%d, %d);\n", xJShort, yJShort);
    glVertex2s(xJShort, yJShort);
}
