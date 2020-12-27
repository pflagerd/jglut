#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutSolidTeapot(JNIEnv *env, jobject object, jdouble size) {
    DPRINTF("glutSolidTeapot(%.17g%s);\n", size, size == (int)size ? ".0" : "");
    glutSolidTeapot(size);
}
