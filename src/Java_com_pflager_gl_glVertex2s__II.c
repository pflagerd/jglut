#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex2s__II(JNIEnv *env, jobject object, jint xJInt, jint yJInt) {
    DPRINTF("glVertex2s(%d, %d);\n", xJInt, yJInt);
    glVertex2s((short)xJInt, (short)yJInt);
}
