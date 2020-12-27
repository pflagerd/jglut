#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor4s(JNIEnv *env, jobject object, jshort redJShort, jshort greenJShort, jshort blueJShort, jshort alphaJShort) {
    DPRINTF("glColor4s(%d, %d, %d, %d);\n", redJShort, greenJShort, blueJShort, alphaJShort);
    glColor4s(redJShort, greenJShort, blueJShort, alphaJShort);

}
