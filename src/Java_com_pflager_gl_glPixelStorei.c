#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPixelStorei(JNIEnv *env, jobject object, jint pnameJInt, jint paramJInt) {
    DPRINTF("glPixelStorei(%d, %d);\n", pnameJInt, paramJInt);
    glPixelStorei(pnameJInt, paramJInt);

}
