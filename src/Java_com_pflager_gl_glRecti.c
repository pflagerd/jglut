#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRecti(JNIEnv *env, jobject object, jint arg0JInt, jint arg1JInt, jint arg2JInt, jint arg3JInt) {
    DPRINTF("glRecti(%d, %d, %d, %d);\n", arg0JInt, arg1JInt, arg2JInt, arg3JInt);
    glRecti(arg0JInt, arg1JInt, arg2JInt, arg3JInt);
}
