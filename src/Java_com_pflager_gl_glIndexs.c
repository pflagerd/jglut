#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glIndexs(JNIEnv *env, jobject object, jshort cJShort) {
    DPRINTF("glIndexs(%d);\n", cJShort);
    glIndexs(cJShort);

}
