#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT jstring JNICALL Java_com_pflager_glu_gluErrorString(JNIEnv *env, jobject object, jint errorJInt) {
    DPRINTF("gluErrorString(%d);\n", errorJInt);
    return (*env)->NewStringUTF(env, (const char*)gluErrorString(errorJInt));
}
