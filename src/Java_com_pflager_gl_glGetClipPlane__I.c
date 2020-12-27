#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jdoubleArray JNICALL Java_com_pflager_gl_glGetClipPlane__I(JNIEnv *env, jobject object, jint planeJInt) {
    DPRINTF("glGetClipPlane(%d);\n", planeJInt);

    const jsize length = 4;

    double double_array[length];

    glGetClipPlane(planeJInt, double_array);

    jdoubleArray jDoubleArray = (*env)->NewDoubleArray(env, length);  // allocate
    if (NULL == jDoubleArray) {
    	return NULL;
    }

    (*env)->SetDoubleArrayRegion(env, jDoubleArray, 0 , length, double_array);  // copy

    return jDoubleArray;
}
