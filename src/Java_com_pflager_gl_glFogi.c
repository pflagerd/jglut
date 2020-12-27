#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glFogi(JNIEnv *env, jobject object, jint pnameJInt, jint paramJInt) {
    DPRINTF("glFogi(%d, %d);\n", pnameJInt, paramJInt);
    glFogi(pnameJInt, paramJInt);

}
