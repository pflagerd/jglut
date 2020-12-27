#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor4ub(JNIEnv *env, jobject object, jbyte redJByte, jbyte greenJByte, jbyte blueJByte, jbyte alphaJByte) {
    DPRINTF("glColor4ub(%d, %d, %d, %d);\n", redJByte, greenJByte, blueJByte, alphaJByte);
    glColor4ub(redJByte, greenJByte, blueJByte, alphaJByte);

}
