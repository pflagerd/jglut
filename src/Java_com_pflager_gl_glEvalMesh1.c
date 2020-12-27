#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEvalMesh1(JNIEnv *env, jobject object, jint modeJInt, jint i1JInt, jint i2JInt) {
    DPRINTF("glEvalMesh1(%d, %d, %d);\n", modeJInt, i1JInt, i2JInt);
    glEvalMesh1(modeJInt, i1JInt, i2JInt);

}
