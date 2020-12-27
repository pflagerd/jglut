#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEdgeFlag__I(JNIEnv *env, jobject object, jint flag) {
    DPRINTF("glEdgeFlag(%s);\n", flag ? "true" : "false");
    glEdgeFlag((unsigned char)flag);
}
