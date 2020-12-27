#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jstring JNICALL Java_com_pflager_gl_glGetString(JNIEnv *env, jobject object, jint nameJInt) {
    DPRINTF("glGetString(%d);\n", nameJInt);
    const GLubyte* theString = glGetString(nameJInt);

    return (*env)->NewStringUTF(env, (const char*)theString);
}
