#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColorMaterial(JNIEnv *env, jobject object, jint faceJInt, jint modeJInt) {
    DPRINTF("glColorMaterial(%d, %d);\n", faceJInt, modeJInt);
    glColorMaterial(faceJInt, modeJInt);
}
