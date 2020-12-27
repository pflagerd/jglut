#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glLightModelfv__I_3F(JNIEnv *env, jobject object, jint pnameJInt, jfloatArray paramsJFloatArray) {
    DPRINTF("glLightModelfv(%d, %p);\n", pnameJInt, paramsJFloatArray);

    jfloat *paramsJFloatCArray = (*env)->GetFloatArrayElements(env, paramsJFloatArray, NULL);
    if (NULL == paramsJFloatCArray) {
    	return;
    }
    jsize length = (*env)->GetArrayLength(env, paramsJFloatArray);
    if (array_length_from_pname(pnameJInt) != length) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "You must pass exactly %d elements for pname == %d", length, pnameJInt);
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    glLightModelfv(pnameJInt, paramsJFloatCArray);

    (*env)->ReleaseFloatArrayElements(env, paramsJFloatArray, paramsJFloatCArray, 0); // release resources
}
