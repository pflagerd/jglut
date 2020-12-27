#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glNewList(JNIEnv *env, jobject object, jint listJInt, jint modeJInt) {
    DPRINTF("glNewList(%d, %d);\n", listJInt, modeJInt);
    glNewList(listJInt, modeJInt);
}
