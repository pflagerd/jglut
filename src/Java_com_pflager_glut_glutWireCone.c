#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutWireCone(JNIEnv *env, jobject object, jdouble base, jdouble height, jint slices, jint stacks) {
    DPRINTF("glutWireCone(%.17g%s, %.17g%s, %d, %d);\n", base, base == (int)base ? ".0" : "", height, height == (int)height ? ".0" : "", slices, stacks);
    glutWireCone(base, height, slices, stacks);
}
