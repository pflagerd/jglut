#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glGetBooleanv__I_3Z(JNIEnv *env, jobject object, jint pnameJInt, jbooleanArray paramsJBooleanArray) {
    DPRINTF("glGetBooleanv(%d, %p);\n", pnameJInt, paramsJBooleanArray);

    jboolean *paramsJBooleanCArray = (*env)->GetBooleanArrayElements(env, paramsJBooleanArray, NULL);
    if (NULL == paramsJBooleanCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, paramsJBooleanArray);
    if (array_length_from_pname(pnameJInt) != length) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", length);
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jboolean Boolean_array[length];

    glGetBooleanv(pnameJInt, Boolean_array);

    for (int i = 0; i < length; i++) {
    	paramsJBooleanCArray[i] = Boolean_array[i];
    }

    (*env)->SetBooleanArrayRegion(env, paramsJBooleanArray, 0 , length, paramsJBooleanCArray);  // copy

    (*env)->ReleaseBooleanArrayElements(env, paramsJBooleanArray, paramsJBooleanCArray, 0); // release resources
}
