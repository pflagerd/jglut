#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glGetClipPlane__I_3D(JNIEnv *env, jobject object, jint planeJInt, jdoubleArray equationJDoubleArray) {
    DPRINTF("glGetClipPlane(%d, %p);\n", planeJInt, equationJDoubleArray);

    jdouble *equationJDoubleCArray = (*env)->GetDoubleArrayElements(env, equationJDoubleArray, NULL);
    if (NULL == equationJDoubleCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, equationJDoubleArray);
    if (4 != length) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", length);
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    double double_array[length];

    glGetClipPlane(planeJInt, double_array);

    for (int i = 0; i < length; i++) {
    	equationJDoubleCArray[i] = double_array[i];
    }

    (*env)->SetDoubleArrayRegion(env, equationJDoubleArray, 0 , length, equationJDoubleCArray);  // copy

    (*env)->ReleaseDoubleArrayElements(env, equationJDoubleArray, equationJDoubleCArray, 0); // release resources
}
