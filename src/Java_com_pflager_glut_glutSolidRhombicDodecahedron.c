#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutSolidRhombicDodecahedron(JNIEnv *env, jobject object) {
    DPRINTF("glutSolidRhombicDodecahedron();\n");
    glutSolidRhombicDodecahedron();
}
