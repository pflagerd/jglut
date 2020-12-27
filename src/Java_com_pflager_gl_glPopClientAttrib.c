#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPopClientAttrib(JNIEnv *env, jobject object) {
    DPRINTF("glPopClientAttrib();\n");
    glPopClientAttrib();
}
