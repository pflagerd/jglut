#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexParameteri(JNIEnv *env, jobject object, jint targetJInt, jint pnameJInt, jint paramJInt) {
    DPRINTF("glTexParameteri(%d, %d, %d);\n", targetJInt, pnameJInt, paramJInt);
    glTexParameteri(targetJInt, pnameJInt, paramJInt);

}
