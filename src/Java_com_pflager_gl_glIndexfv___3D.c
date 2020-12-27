#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glIndexfv___3D(JNIEnv *env, jobject object, jdoubleArray cJDoubleArray) {
    DPRINTF("glIndexfv(%p);\n", cJDoubleArray);

	if (cJDoubleArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 1);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, cJDoubleArray);
    if (length != 1) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 1);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jdouble* jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, cJDoubleArray, NULL);

    glIndexdv(jdoubleArrayElements);

	(*env)->ReleaseDoubleArrayElements(env, cJDoubleArray, jdoubleArrayElements, 0); // release resources
}
