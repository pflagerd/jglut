#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor3i(JNIEnv *env, jobject object, jint redJInt, jint greenJInt, jint blueJInt) {
    DPRINTF("glColor3i(%d, %d, %d);\n", redJInt, greenJInt, blueJInt);
    glColor3i(redJInt, greenJInt, blueJInt);

}
