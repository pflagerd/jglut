#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glIndexi(JNIEnv *env, jobject object, jint cJInt) {
    DPRINTF("glIndexi(%d);\n", cJInt);
    glIndexi(cJInt);

}
