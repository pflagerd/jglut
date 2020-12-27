#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor3b(JNIEnv *env, jobject object, jbyte redJByte, jbyte greenJByte, jbyte blueJByte) {
    DPRINTF("glColor3b(%d, %d, %d);\n", redJByte, greenJByte, blueJByte);
    glColor3b(redJByte, greenJByte, blueJByte);

}
