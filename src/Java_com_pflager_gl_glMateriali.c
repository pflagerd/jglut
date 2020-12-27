#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glMateriali(JNIEnv *env, jobject object, jint faceJInt, jint pnameJInt, jint paramJInt) {
    DPRINTF("glMateriali(%d, %d, %d);\n", faceJInt, pnameJInt, paramJInt);
    glMateriali(faceJInt, pnameJInt, paramJInt);
}
