#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glGetFloatv__I_3D(JNIEnv *env, jobject object, jint pname, jdoubleArray paramsJDoubleArray) {
    DPRINTF("glGetFloatv(%d, 0x%p);\n", pname, paramsJDoubleArray);

    jdouble *paramsJDoubleCArray = (*env)->GetDoubleArrayElements(env, paramsJDoubleArray, NULL);
    if (NULL == paramsJDoubleCArray) {
    	return;
    }
    jsize length = (*env)->GetArrayLength(env, paramsJDoubleArray);
    if (GL_CURRENT_COLOR == pname && length != 4) { // TODO: DPP: 190331T182100: Need a bunch of these checks.
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 4 elements.");
        return;
    }

    float float_array[length];

    glGetFloatv(pname, float_array);

    for (int i = 0; i < length; i++) {
    	paramsJDoubleCArray[i] = float_array[i];
    }

    (*env)->SetDoubleArrayRegion(env, paramsJDoubleArray, 0 , length, paramsJDoubleCArray);  // copy

    (*env)->ReleaseDoubleArrayElements(env, paramsJDoubleArray, paramsJDoubleCArray, 0); // release resources
}
