#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glCallList(JNIEnv *env, jobject object, jint listJInt) {
    DPRINTF("glCallList(%d);\n", listJInt);
    glCallList(listJInt);
}
