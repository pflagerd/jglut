#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex3i(JNIEnv *env, jobject object, jint xJInt, jint yJInt, jint zJInt) {
    DPRINTF("glVertex3i(%d, %d, %d);\n", xJInt, yJInt, zJInt);
    glVertex3i(xJInt, yJInt, zJInt);
}
