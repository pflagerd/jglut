#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glIndexiv(JNIEnv *env, jobject object, jintArray cJIntArray) {
    DPRINTF("glIndexiv(%p);\n", cJIntArray);

	if (cJIntArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 1);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, cJIntArray);
    if (length != 1) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 1);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jint* jintArrayElements = (*env)->GetIntArrayElements(env, cJIntArray, NULL);

    glIndexiv(jintArrayElements);

	(*env)->ReleaseIntArrayElements(env, cJIntArray, jintArrayElements, 0); // release resources
}
