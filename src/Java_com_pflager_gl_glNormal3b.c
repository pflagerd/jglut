#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glNormal3b(JNIEnv *env, jobject object, jbyte nxJByte, jbyte nyJByte, jbyte nzJByte) {
    DPRINTF("glNormal3b(%d, %d, %d);\n", nxJByte, nyJByte, nzJByte);
    glNormal3b(nxJByte, nyJByte, nzJByte);

}
