#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor3us(JNIEnv *env, jobject object, jshort redJShort, jshort greenJShort, jshort blueJShort) {
    DPRINTF("glColor3us(%d, %d, %d);\n", redJShort, greenJShort, blueJShort);
    glColor3us(redJShort, greenJShort, blueJShort);

}
