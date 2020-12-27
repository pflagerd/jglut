#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jint JNICALL Java_com_pflager_gl_glGenLists(JNIEnv *env, jobject object, jint rangeJInt) {
    DPRINTF("glGenLists(%d);\n", rangeJInt);
    return glGenLists(rangeJInt);
}
