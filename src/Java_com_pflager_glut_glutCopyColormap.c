#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutCopyColormap(JNIEnv *env, jobject object, jint windowJInt) {
    DPRINTF("glutCopyColormap(%d);\n", windowJInt);
    glutCopyColormap(windowJInt);

}
