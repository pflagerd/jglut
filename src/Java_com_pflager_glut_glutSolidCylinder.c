#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutSolidCylinder(JNIEnv *env, jobject object, jdouble radius, jdouble height, jint slices, jint stacks) {
    DPRINTF("glutSolidCylinder(%.17g%s, %.17g%s, %d, %d);\n", radius, radius == (int)radius ? ".0" : "", height, height == (int)height ? ".0" : "", slices, stacks);
    glutSolidCylinder(radius, height, slices, stacks);
}
