#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRectfv___3F_3F(JNIEnv *env, jobject object, jfloatArray v1JFloatArray, jfloatArray v2JFloatArray) {
    DPRINTF("glRectfv(%p, %p);\n", v1JFloatArray, v2JFloatArray);

    const jfloat *v1JFloatCArray = (*env)->GetFloatArrayElements(env, v1JFloatArray, NULL);
    if (NULL == v1JFloatCArray) {
    	return;
    }
    jsize length = (*env)->GetArrayLength(env, v1JFloatArray);
    if (length != 2) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "You must pass exactly 2 elements for v1");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    const jfloat *v2JFloatCArray = (*env)->GetFloatArrayElements(env, v2JFloatArray, NULL);
    if (NULL == v2JFloatCArray) {
    	return;
    }

    length = (*env)->GetArrayLength(env, v2JFloatArray);
    if (length != 2) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "You must pass exactly 2 elements for v2");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    glRectfv(v1JFloatCArray, v2JFloatCArray);

    (*env)->ReleaseFloatArrayElements(env, v2JFloatArray, (jfloat*)v2JFloatCArray, 0); // release resources
    (*env)->ReleaseFloatArrayElements(env, v1JFloatArray, (jfloat*)v1JFloatCArray, 0); // release resources
}
