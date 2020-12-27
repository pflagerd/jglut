#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glEvalCoord2fv(JNIEnv *env, jobject object, jdoubleArray uJDoubleArray) {
    DPRINTF("glEvalCoord2fv(%p);\n", uJDoubleArray);

	if (uJDoubleArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 2);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, uJDoubleArray);
    if (length != 2) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 2);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jdouble* jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, uJDoubleArray, NULL);

    glEvalCoord2dv(jdoubleArrayElements);

	(*env)->ReleaseDoubleArrayElements(env, uJDoubleArray, jdoubleArrayElements, 0); // release resources
}
