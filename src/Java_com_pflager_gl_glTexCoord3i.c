#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord3i(JNIEnv *env, jobject object, jint sJInt, jint tJInt, jint rJInt) {
    DPRINTF("glTexCoord3i(%d, %d, %d);\n", sJInt, tJInt, rJInt);
    glTexCoord3i(sJInt, tJInt, rJInt);

}
