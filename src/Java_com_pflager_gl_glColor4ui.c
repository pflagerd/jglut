#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor4ui(JNIEnv *env, jobject object, jint redJInt, jint greenJInt, jint blueJInt, jint alphaJInt) {
    DPRINTF("glColor4ui(%d, %d, %d, %d);\n", redJInt, greenJInt, blueJInt, alphaJInt);
    glColor4ui(redJInt, greenJInt, blueJInt, alphaJInt);

}
