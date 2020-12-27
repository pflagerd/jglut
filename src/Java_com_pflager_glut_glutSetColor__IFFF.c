#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutSetColor__IFFF(JNIEnv *env, jobject object, jint colorJInt, jfloat redJFloat, jfloat greenJFloat, jfloat blueJFloat) {
    DPRINTF("glutSetColor(%d, %.8g%sf, %.8g%sf, %.8g%sf);\n", colorJInt, redJFloat, redJFloat == (int)redJFloat ? ".0" : "", greenJFloat, greenJFloat == (int)greenJFloat ? ".0" : "", blueJFloat, blueJFloat == (int)blueJFloat ? ".0" : "");
    glutSetColor(colorJInt, redJFloat, greenJFloat, blueJFloat);

}
