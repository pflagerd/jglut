#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glNormal3i(JNIEnv *env, jobject object, jint nxJInt, jint nyJInt, jint nzJInt) {
    DPRINTF("glNormal3i(%d, %d, %d);\n", nxJInt, nyJInt, nzJInt);
    glNormal3i(nxJInt, nyJInt, nzJInt);

}
