#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutInit__(JNIEnv *env, jobject object) {
    DPRINTF("glutInit();\n");

    int argc = 1;
    char* argv = "jglut";

    glutInit(&argc, &argv);
}
