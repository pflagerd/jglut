#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glLighti(JNIEnv *env, jobject object, jint lightJInt, jint pnameJInt, jint paramJInt) {
    DPRINTF("glLighti(%d, %d, %d);\n", lightJInt, pnameJInt, paramJInt);
    glLighti(lightJInt, pnameJInt, paramJInt);
}
