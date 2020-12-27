#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEdgeFlagv___3Z(JNIEnv *env, jobject object, jbooleanArray flagJBooleanArray) {
    DPRINTF("glEdgeFlagv(%p);\n", flagJBooleanArray);

	if (flagJBooleanArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 1);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, flagJBooleanArray);
    if (length != 1) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 1);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jboolean* jbooleanArrayElements = (*env)->GetBooleanArrayElements(env, flagJBooleanArray, NULL);

    glEdgeFlagv(jbooleanArrayElements);

	(*env)->ReleaseBooleanArrayElements(env, flagJBooleanArray, jbooleanArrayElements, 0); // release resources
}
