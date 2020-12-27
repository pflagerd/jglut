#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glGetIntegerv__I_3I(JNIEnv *env, jobject object, jint pname, jintArray paramsJIntArray) {
    DPRINTF("glGetIntegerv(%d, 0x%p);\n", pname, paramsJIntArray);
    jint *paramsJIntCArray = (*env)->GetIntArrayElements(env, paramsJIntArray, NULL);
    if (NULL == paramsJIntCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, paramsJIntArray);
    if (length != array_length_from_pname(pname)) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 4 elements.");
        return;
    }

    int int_array[length];

    glGetIntegerv(pname, int_array);

    for (int i = 0; i < length; i++) {
    	paramsJIntCArray[i] = int_array[i];
    }

    (*env)->SetIntArrayRegion(env, paramsJIntArray, 0 , length, paramsJIntCArray);  // copy

    (*env)->ReleaseIntArrayElements(env, paramsJIntArray, paramsJIntCArray, 0); // release resources
}
