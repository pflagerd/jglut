#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutLeaveMainLoop(JNIEnv *env, jobject object) {
    DPRINTF("glutLeaveMainLoop();\n");
    glutLeaveMainLoop();
}
