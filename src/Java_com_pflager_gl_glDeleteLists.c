#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glDeleteLists(JNIEnv *env, jobject object, jint listJInt, jint rangeJInt) {
    DPRINTF("glDeleteLists(%d, %d);\n", listJInt, rangeJInt);
    glDeleteLists(listJInt, rangeJInt);
}
