#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutSet(JNIEnv *env, jobject object, jint eWhat, jint value) {
    DPRINTF("glutSet(%d, %d);\n", eWhat, value);
    glutSetOption(eWhat, value);
}
