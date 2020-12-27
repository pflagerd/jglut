#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex4s__IIII(JNIEnv *env, jobject object, jint xJInt, jint yJInt, jint zJInt, jint wJInt) {
    DPRINTF("glVertex4s(%d, %d, %d, %d);\n", xJInt, yJInt, zJInt, wJInt);
    glVertex4s((short)xJInt, (short)yJInt, (short)zJInt, (short)wJInt);
}
