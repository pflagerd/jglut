#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutWireTorus(JNIEnv *env, jobject object, jdouble innerRadius, jdouble outerRadius, jint sides, jint rings) {
    DPRINTF("glutWireTorus(%.17g%s, %.17g%s, %d, %d);\n", innerRadius, innerRadius == (int)innerRadius ? ".0" : "", outerRadius, outerRadius == (int)outerRadius ? ".0" : "", sides, rings);
    glutWireTorus(innerRadius, outerRadius, sides, rings);
}
