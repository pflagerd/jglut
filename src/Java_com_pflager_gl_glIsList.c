#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jint JNICALL Java_com_pflager_gl_glIsList(JNIEnv *env, jobject object, jint listJInt) {
    DPRINTF("glIsList(%d);\n", listJInt);
    return glIsList(listJInt);
}
