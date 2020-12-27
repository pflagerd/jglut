#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos4i(JNIEnv *env, jobject object, jint xJInt, jint yJInt, jint zJInt, jint wJInt) {
    DPRINTF("glRasterPos4i(%d, %d, %d, %d);\n", xJInt, yJInt, zJInt, wJInt);
    glRasterPos4i(xJInt, yJInt, zJInt, wJInt);

}
