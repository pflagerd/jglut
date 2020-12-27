#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex2dv(JNIEnv *env, jobject object, jdoubleArray vJDoubleArray) {
    DPRINTF("glVertex2dv(%p);\n", vJDoubleArray);

    if (vJDoubleArray == NULL) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 2 elements.");
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJDoubleArray);
    if (length != 2) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 2 elements.");
        return;
    }

    jdouble *vJDoubleArrayElements = (*env)->GetDoubleArrayElements(env, vJDoubleArray, NULL);

    DPRINTF("glVertex2dv(new double[] {");
    for (unsigned i = 0; i < length; i++) {
    	if (i != 0) {
    		DPRINTF(", ");
    	}
    	DPRINTF("%.17g%s", vJDoubleArrayElements[i], vJDoubleArrayElements[i] == (int)vJDoubleArrayElements[i] ? ".0" : "");
    }
    DPRINTF("});\n");

    glVertex2dv(vJDoubleArrayElements);

    (*env)->ReleaseDoubleArrayElements(env, vJDoubleArray, vJDoubleArrayElements, 0); // release resources
}
