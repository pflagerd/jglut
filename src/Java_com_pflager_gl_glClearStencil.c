#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glClearStencil(JNIEnv *env, jobject object, jint sJInt) {
    DPRINTF("glClearStencil(%d);\n", sJInt);
    glClearStencil(sJInt);

}
