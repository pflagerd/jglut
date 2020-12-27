#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord1s(JNIEnv *env, jobject object, jshort sJShort) {
    DPRINTF("glTexCoord1s(%d);\n", sJShort);
    glTexCoord1s(sJShort);

}
