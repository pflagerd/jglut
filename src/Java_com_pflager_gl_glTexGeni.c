#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexGeni(JNIEnv *env, jobject object, jint coordJInt, jint pnameJInt, jint paramJInt) {
    DPRINTF("glTexGeni(%d, %d, %d);\n", coordJInt, pnameJInt, paramJInt);
    glTexGeni(coordJInt, pnameJInt, paramJInt);

}
