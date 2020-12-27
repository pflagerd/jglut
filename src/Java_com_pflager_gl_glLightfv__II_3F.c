#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glLightfv__II_3F(JNIEnv *env, jobject object, jint light, jint pname, jfloatArray paramsJFloatArray) {
    DPRINTF("glLightfv(%d, %d, %p);\n", light, pname, paramsJFloatArray);

    jfloat *paramsJFloatCArray = (*env)->GetFloatArrayElements(env, paramsJFloatArray, NULL);
    if (NULL == paramsJFloatCArray) {
    	return;
    }
    jsize length = (*env)->GetArrayLength(env, paramsJFloatArray);
    if (array_length_from_pname(pname) != length) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "glLightfv(int light, int pname, float[] params): You must pass exactly %d elements for pname == %d", length, pname);
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    glLightfv(light, pname, paramsJFloatCArray);

    (*env)->ReleaseFloatArrayElements(env, paramsJFloatArray, paramsJFloatCArray, 0); // release resources
}
