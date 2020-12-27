#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glLoadMatrixd(JNIEnv *env, jobject object, jdoubleArray mJDoubleArray) {
    DPRINTF("glLoadMatrixd(%p);\n", mJDoubleArray);

	if (mJDoubleArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 16);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, mJDoubleArray);
    if (length != 16) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 16);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jdouble* jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, mJDoubleArray, NULL);

    glLoadMatrixd(jdoubleArrayElements);

	(*env)->ReleaseDoubleArrayElements(env, mJDoubleArray, jdoubleArrayElements, 0); // release resources
}
