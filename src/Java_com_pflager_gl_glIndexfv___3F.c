#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glIndexfv___3F(JNIEnv *env, jobject object, jfloatArray cJFloatArray) {
    DPRINTF("glIndexfv(%p);\n", cJFloatArray);

	if (cJFloatArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 1);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, cJFloatArray);
    if (length != 1) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 1);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jfloat* jfloatArrayElements = (*env)->GetFloatArrayElements(env, cJFloatArray, NULL);

    glIndexfv(jfloatArrayElements);

	(*env)->ReleaseFloatArrayElements(env, cJFloatArray, jfloatArrayElements, 0); // release resources
}
