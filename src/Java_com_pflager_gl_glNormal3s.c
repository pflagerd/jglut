#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glNormal3s(JNIEnv *env, jobject object, jshort nxJShort, jshort nyJShort, jshort nzJShort) {
    DPRINTF("glNormal3s(%d, %d, %d);\n", nxJShort, nyJShort, nzJShort);
    glNormal3s(nxJShort, nyJShort, nzJShort);

}
