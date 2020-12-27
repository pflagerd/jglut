#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT int JNICALL Java_com_pflager_glut_glutGet(JNIEnv *env, jobject object, jint query) {
    DPRINTF("glutGet(%d);\n", query);
    return glutGet(query);
}
