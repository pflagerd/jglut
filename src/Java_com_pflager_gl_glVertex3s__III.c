#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex3s__III(JNIEnv *env, jobject object, jint xJInt, jint yJInt, jint zJInt) {
    DPRINTF("glVertex3s(%d, %d, %d);\n", xJInt, yJInt, zJInt);
    glVertex3s((short)xJInt, (short)yJInt, (short)zJInt);
}
