#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glMaterialfv__II_3D(JNIEnv *env, jobject object, jint face, jint pname, jdoubleArray paramsJDoubleArray) {
    DPRINTF("glMaterialfv(%d, %d, %p);\n", face, pname, paramsJDoubleArray);
    jdouble *paramsJDoubleCArray = (*env)->GetDoubleArrayElements(env, paramsJDoubleArray, NULL);
    if (NULL == paramsJDoubleCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, paramsJDoubleArray);
    if (array_length_from_pname(pname) != length) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "glMaterialfv(int face, int pname, double[] params): You must pass exactly %d elements for pname == %d", length, pname);
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }
    DPRINTF("length == %d\n", length);

    float float_array[length];
    for (int i = 0; i < length; i++) {
    	float_array[i] = (float)paramsJDoubleCArray[i];
    }

    glMaterialfv(face, pname, float_array);

    (*env)->ReleaseDoubleArrayElements(env, paramsJDoubleArray, paramsJDoubleCArray, 0); // release resources
}
