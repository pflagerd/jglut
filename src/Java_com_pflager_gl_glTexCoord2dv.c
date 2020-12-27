#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord2dv(JNIEnv *env, jobject object, jdoubleArray vJDoubleArray) {
    DPRINTF("glTexCoord2dv(%p);\n", vJDoubleArray);

	if (vJDoubleArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 2);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJDoubleArray);
    if (length != 2) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 2);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jdouble* jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, vJDoubleArray, NULL);

    glTexCoord2dv(jdoubleArrayElements);

	(*env)->ReleaseDoubleArrayElements(env, vJDoubleArray, jdoubleArrayElements, 0); // release resources
}
