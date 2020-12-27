#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor4us(JNIEnv *env, jobject object, jshort redJShort, jshort greenJShort, jshort blueJShort, jshort alphaJShort) {
    DPRINTF("glColor4us(%d, %d, %d, %d);\n", redJShort, greenJShort, blueJShort, alphaJShort);
    glColor4us(redJShort, greenJShort, blueJShort, alphaJShort);

}
