#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutSetColor__IDDD(JNIEnv *env, jobject object, jint colorJInt, jdouble redJDouble, jdouble greenJDouble, jdouble blueJDouble) {
    DPRINTF("glutSetColor(%d, %.17g%s, %.17g%s, %.17g%s);\n", colorJInt, redJDouble, redJDouble == (int)redJDouble ? ".0" : "", greenJDouble, greenJDouble == (int)greenJDouble ? ".0" : "", blueJDouble, blueJDouble == (int)blueJDouble ? ".0" : "");
    glutSetColor(colorJInt, (float)redJDouble, (float)greenJDouble, (float)blueJDouble);

}
