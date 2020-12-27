#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor3ui(JNIEnv *env, jobject object, jint redJInt, jint greenJInt, jint blueJInt) {
    DPRINTF("glColor3ui(%d, %d, %d);\n", redJInt, greenJInt, blueJInt);
    glColor3ui(redJInt, greenJInt, blueJInt);

}
