#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutSolidDodecahedron(JNIEnv *env, jobject object) {
    DPRINTF("glutSolidDodecahedron();\n");
    glutSolidDodecahedron();
}
