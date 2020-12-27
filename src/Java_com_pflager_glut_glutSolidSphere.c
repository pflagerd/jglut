#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutSolidSphere(JNIEnv *env, jobject object, jdouble radius, jint slices, jint stacks) {
    DPRINTF("glutSolidSphere(%.17g%s, %d, %d);\n", radius, radius == (int)radius ? ".0" : "", slices, stacks);
    glutSolidSphere(radius, slices, stacks);
}
