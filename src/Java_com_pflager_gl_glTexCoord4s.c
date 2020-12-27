#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord4s(JNIEnv *env, jobject object, jshort sJShort, jshort tJShort, jshort rJShort, jshort qJShort) {
    DPRINTF("glTexCoord4s(%d, %d, %d, %d);\n", sJShort, tJShort, rJShort, qJShort);
    glTexCoord4s(sJShort, tJShort, rJShort, qJShort);

}
