#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor4dv(JNIEnv *env, jobject object, jdoubleArray vJDoubleArray) {
    DPRINTF("glColor4dv(%p);\n", vJDoubleArray);

	if (vJDoubleArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 4);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJDoubleArray);
    if (length != 4) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 4);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jdouble* jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, vJDoubleArray, NULL);

    glColor4dv(jdoubleArrayElements);

	(*env)->ReleaseDoubleArrayElements(env, vJDoubleArray, jdoubleArrayElements, 0); // release resources
}
