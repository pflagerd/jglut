#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEvalCoord1dv(JNIEnv *env, jobject object, jdoubleArray uJDoubleArray) {
    DPRINTF("glEvalCoord1dv(%p);\n", uJDoubleArray);

	if (uJDoubleArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 1);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, uJDoubleArray);
    if (length != 1) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 1);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jdouble* jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, uJDoubleArray, NULL);

    glEvalCoord1dv(jdoubleArrayElements);

	(*env)->ReleaseDoubleArrayElements(env, uJDoubleArray, jdoubleArrayElements, 0); // release resources
}
