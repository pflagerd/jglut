#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos2i(JNIEnv *env, jobject object, jint xJInt, jint yJInt) {
    DPRINTF("glRasterPos2i(%d, %d);\n", xJInt, yJInt);
    glRasterPos2i(xJInt, yJInt);

}
