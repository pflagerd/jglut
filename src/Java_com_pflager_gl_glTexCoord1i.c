#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord1i(JNIEnv *env, jobject object, jint sJInt) {
    DPRINTF("glTexCoord1i(%d);\n", sJInt);
    glTexCoord1i(sJInt);

}
