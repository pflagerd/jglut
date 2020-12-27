#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glScissor(JNIEnv *env, jobject object, jint xJInt, jint yJInt, jint widthJInt, jint heightJInt) {
    DPRINTF("glScissor(%d, %d, %d, %d);\n", xJInt, yJInt, widthJInt, heightJInt);
    glScissor(xJInt, yJInt, widthJInt, heightJInt);
}
