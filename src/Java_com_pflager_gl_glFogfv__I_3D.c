#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glFogfv__I_3D(JNIEnv *env, jobject object, jint pnameJInt, jdoubleArray paramsJDoubleArray) {
    DPRINTF("glFogfv(%d, %p);\n", pnameJInt, paramsJDoubleArray);

	if (paramsJDoubleArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", array_length_from_pname(pnameJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, paramsJDoubleArray);
    if (length != array_length_from_pname(pnameJInt)) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", array_length_from_pname(pnameJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jdouble* jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, paramsJDoubleArray, NULL);

    float float_array[length];
    for (int i = 0; i < length; i++) {
    	float_array[i] = jdoubleArrayElements[i];
    }

    glFogfv(pnameJInt, float_array);

	(*env)->ReleaseDoubleArrayElements(env, paramsJDoubleArray, jdoubleArrayElements, 0); // release resources
}
