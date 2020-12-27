#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glGetDoublev__I_3D(JNIEnv *env, jobject object, jint pname, jdoubleArray paramsJDoubleArray) {
    DPRINTF("glGetDoublev(%d, %p);\n", pname, paramsJDoubleArray);

    jdouble *paramsJDoubleCArray = (*env)->GetDoubleArrayElements(env, paramsJDoubleArray, NULL);
    if (NULL == paramsJDoubleCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, paramsJDoubleArray);
    if (array_length_from_pname(pname) != length) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", length);
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    double double_array[length];

    glGetDoublev(pname, double_array);

    for (int i = 0; i < length; i++) {
    	paramsJDoubleCArray[i] = double_array[i];
    }

    (*env)->SetDoubleArrayRegion(env, paramsJDoubleArray, 0 , length, paramsJDoubleCArray);  // copy

    (*env)->ReleaseDoubleArrayElements(env, paramsJDoubleArray, paramsJDoubleCArray, 0); // release resources
}
