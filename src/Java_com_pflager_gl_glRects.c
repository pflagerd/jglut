#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRects(JNIEnv *env, jobject object, jint x1JInt, jint y1JInt, jint x2JInt, jint y2JInt) {
    DPRINTF("glRects(%d, %d, %d, %d);\n", x1JInt, y1JInt, x2JInt, y2JInt);
    glRects(x1JInt, y1JInt, x2JInt, y2JInt);
}
