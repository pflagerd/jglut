#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT jfloat JNICALL Java_com_pflager_glut_glutGetColor(JNIEnv *env, jobject object, jint colorJInt, jint componentJInt) {
    DPRINTF("glutGetColor(%d, %d);\n", colorJInt, componentJInt);
    return glutGetColor(colorJInt, componentJInt);
}
