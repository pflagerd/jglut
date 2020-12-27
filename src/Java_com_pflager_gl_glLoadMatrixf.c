#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glLoadMatrixf(JNIEnv *env, jobject object, jfloatArray mJFloatArray) {
    DPRINTF("glLoadMatrixf(%p);\n", mJFloatArray);

	if (mJFloatArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 16);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, mJFloatArray);
    if (length != 16) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 16);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jfloat* jfloatArrayElements = (*env)->GetFloatArrayElements(env, mJFloatArray, NULL);

    glLoadMatrixf(jfloatArrayElements);

	(*env)->ReleaseFloatArrayElements(env, mJFloatArray, jfloatArrayElements, 0); // release resources
}
