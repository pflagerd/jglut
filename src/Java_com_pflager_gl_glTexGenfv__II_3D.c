#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexGenfv__II_3D(JNIEnv *env, jobject object, jint coordJInt, jint pnameJInt, jdoubleArray paramsJDoubleArray) {
    DPRINTF("glTexGenfv(%d, %d, %p);\n", coordJInt, pnameJInt, paramsJDoubleArray);

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

    glTexGendv(coordJInt, pnameJInt, jdoubleArrayElements);

	(*env)->ReleaseDoubleArrayElements(env, paramsJDoubleArray, jdoubleArrayElements, 0); // release resources
}
