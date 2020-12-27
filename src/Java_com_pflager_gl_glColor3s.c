#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor3s(JNIEnv *env, jobject object, jshort redJShort, jshort greenJShort, jshort blueJShort) {
    DPRINTF("glColor3s(%d, %d, %d);\n", redJShort, greenJShort, blueJShort);
    glColor3s(redJShort, greenJShort, blueJShort);

}
