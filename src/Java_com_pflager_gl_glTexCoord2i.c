#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord2i(JNIEnv *env, jobject object, jint sJInt, jint tJInt) {
    DPRINTF("glTexCoord2i(%d, %d);\n", sJInt, tJInt);
    glTexCoord2i(sJInt, tJInt);

}
