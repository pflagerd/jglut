#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEdgeFlagv___3I(JNIEnv *env, jobject object, jintArray flagJIntArray) {
    DPRINTF("glEdgeFlagv(%p);\n", flagJIntArray);

	if (flagJIntArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 1);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, flagJIntArray);
    if (length != 1) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 1);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jint* jintArrayElements = (*env)->GetIntArrayElements(env, flagJIntArray, NULL);

    glEdgeFlagv((const GLboolean*)jintArrayElements);

	(*env)->ReleaseIntArrayElements(env, flagJIntArray, jintArrayElements, 0); // release resources
}
