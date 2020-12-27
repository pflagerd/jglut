#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glDisableClientState(JNIEnv *env, jobject object, jint capJInt) {
    DPRINTF("glDisableClientState(%d);\n", capJInt);
    glDisableClientState(capJInt);
}
