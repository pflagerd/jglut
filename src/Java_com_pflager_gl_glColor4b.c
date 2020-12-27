#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor4b(JNIEnv *env, jobject object, jbyte redJByte, jbyte greenJByte, jbyte blueJByte, jbyte alphaJByte) {
    DPRINTF("glColor4b(%d, %d, %d, %d);\n", redJByte, greenJByte, blueJByte, alphaJByte);
    glColor4b(redJByte, greenJByte, blueJByte, alphaJByte);

}
