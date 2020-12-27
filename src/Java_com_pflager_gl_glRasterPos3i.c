#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos3i(JNIEnv *env, jobject object, jint xJInt, jint yJInt, jint zJInt) {
    DPRINTF("glRasterPos3i(%d, %d, %d);\n", xJInt, yJInt, zJInt);
    glRasterPos3i(xJInt, yJInt, zJInt);

}
