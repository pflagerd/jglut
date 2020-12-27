#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glBlendFunc(JNIEnv *env, jobject object, jint sfactorJInt, jint dfactorJInt) {
    DPRINTF("glBlendFunc(%d, %d);\n", sfactorJInt, dfactorJInt);
    glBlendFunc(sfactorJInt, dfactorJInt);
}
