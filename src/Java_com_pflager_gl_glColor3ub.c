#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor3ub(JNIEnv *env, jobject object, jbyte redJByte, jbyte greenJByte, jbyte blueJByte) {
    DPRINTF("glColor3ub(%d, %d, %d);\n", redJByte, greenJByte, blueJByte);
    glColor3ub(redJByte, greenJByte, blueJByte);

}
