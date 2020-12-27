#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord4i(JNIEnv *env, jobject object, jint sJInt, jint tJInt, jint rJInt, jint qJInt) {
    DPRINTF("glTexCoord4i(%d, %d, %d, %d);\n", sJInt, tJInt, rJInt, qJInt);
    glTexCoord4i(sJInt, tJInt, rJInt, qJInt);

}
