#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glLightModeli(JNIEnv *env, jobject object, jint pnameJInt, jint paramJInt) {
    DPRINTF("glLightModeli(%d, %d);\n", pnameJInt, paramJInt);
    glLightModeli(pnameJInt, paramJInt);
}
