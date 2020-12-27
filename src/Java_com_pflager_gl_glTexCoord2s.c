#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord2s(JNIEnv *env, jobject object, jshort sJShort, jshort tJShort) {
    DPRINTF("glTexCoord2s(%d, %d);\n", sJShort, tJShort);
    glTexCoord2s(sJShort, tJShort);

}
