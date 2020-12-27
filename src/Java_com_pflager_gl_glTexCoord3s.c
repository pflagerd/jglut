#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord3s(JNIEnv *env, jobject object, jshort sJShort, jshort tJShort, jshort rJShort) {
    DPRINTF("glTexCoord3s(%d, %d, %d);\n", sJShort, tJShort, rJShort);
    glTexCoord3s(sJShort, tJShort, rJShort);

}
