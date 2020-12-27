#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRectfv___3D_3D(JNIEnv *env, jobject object, jdoubleArray v1JDoubleArray, jdoubleArray v2JDoubleArray) {
    DPRINTF("glRectfv(%p, %p);\n", v1JDoubleArray, v2JDoubleArray);

    const jdouble *v1JDoubleCArray = (*env)->GetDoubleArrayElements(env, v1JDoubleArray, NULL);
    if (NULL == v1JDoubleCArray) {
    	return;
    }
    jsize length = (*env)->GetArrayLength(env, v1JDoubleArray);
    if (length != 2) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "You must pass exactly 2 elements for v1");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    const jdouble *v2JDoubleCArray = (*env)->GetDoubleArrayElements(env, v2JDoubleArray, NULL);
    if (NULL == v2JDoubleCArray) {
    	return;
    }
    length = (*env)->GetArrayLength(env, v2JDoubleArray);
    if (length != 2) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "You must pass exactly 2 elements for v2");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    glRectdv(v1JDoubleCArray, v2JDoubleCArray);

    (*env)->ReleaseDoubleArrayElements(env, v2JDoubleArray, (jdouble*)v2JDoubleCArray, 0); // release resources
    (*env)->ReleaseDoubleArrayElements(env, v1JDoubleArray, (jdouble*)v1JDoubleCArray, 0); // release resources
}
