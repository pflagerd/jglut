#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jint JNICALL Java_com_pflager_gl_glIsEnabled(JNIEnv *env, jobject object, jint capJInt) {
    DPRINTF("glIsEnabled(%d);\n", capJInt);
    return glIsEnabled(capJInt);
}
