#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEvalPoint2(JNIEnv *env, jobject object, jint iJInt, jint jJInt) {
    DPRINTF("glEvalPoint2(%d, %d);\n", iJInt, jJInt);
    glEvalPoint2(iJInt, jJInt);

}
