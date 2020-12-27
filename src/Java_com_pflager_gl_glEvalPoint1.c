#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEvalPoint1(JNIEnv *env, jobject object, jint iJInt) {
    DPRINTF("glEvalPoint1(%d);\n", iJInt);
    glEvalPoint1(iJInt);

}
