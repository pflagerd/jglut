#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glGetFloatv__I_3F(JNIEnv *env, jobject object, jint pname, jfloatArray paramsJFloatArray) {
    DPRINTF("glGetFloatv(%d, %p);\n", pname, paramsJFloatArray);

    jfloat *paramsJFloatCArray = (*env)->GetFloatArrayElements(env, paramsJFloatArray, NULL);
    if (NULL == paramsJFloatCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, paramsJFloatArray);
    if (GL_CURRENT_COLOR == pname && length != 4) { // TODO: DPP: 190331T182100: Need a bunch of these checks.
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 4 elements.");
        return;
    }

    float float_array[length];

    glGetFloatv(pname, float_array);

    for (int i = 0; i < length; i++) {
    	paramsJFloatCArray[i] = float_array[i];
    }

    (*env)->SetFloatArrayRegion(env, paramsJFloatArray, 0 , length, paramsJFloatCArray);  // copy

    (*env)->ReleaseFloatArrayElements(env, paramsJFloatArray, paramsJFloatCArray, 0); // release resources
}
