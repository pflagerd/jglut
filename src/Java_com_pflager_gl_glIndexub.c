#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glIndexub(JNIEnv *env, jobject object, jbyte cJByte) {
    DPRINTF("glIndexub(%d);\n", cJByte);
    glIndexub(cJByte);

}
