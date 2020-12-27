#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEvalMesh2(JNIEnv *env, jobject object, jint modeJInt, jint i1JInt, jint i2JInt, jint j1JInt, jint j2JInt) {
    DPRINTF("glEvalMesh2(%d, %d, %d, %d, %d);\n", modeJInt, i1JInt, i2JInt, j1JInt, j2JInt);
    glEvalMesh2(modeJInt, i1JInt, i2JInt, j1JInt, j2JInt);

}
