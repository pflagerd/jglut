#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRectiv(JNIEnv *env, jobject object, jintArray v1JIntArray, jintArray v2JIntArray) {
    DPRINTF("glRectiv(%p, %p);\n", v1JIntArray, v2JIntArray);

    const jint *v1JIntCArray = (*env)->GetIntArrayElements(env, v1JIntArray, NULL);
    if (NULL == v1JIntCArray) {
    	return;
    }
    jsize length = (*env)->GetArrayLength(env, v1JIntArray);
    if (length != 2) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "You must pass exactly 2 elements for v1");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    const jint *v2JIntCArray = (*env)->GetIntArrayElements(env, v2JIntArray, NULL);
    if (NULL == v2JIntCArray) {
    	return;
    }

    length = (*env)->GetArrayLength(env, v2JIntArray);
    if (length != 2) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "You must pass exactly 2 elements for v2");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    glRectiv(v1JIntCArray, v2JIntCArray);

    (*env)->ReleaseIntArrayElements(env, v2JIntArray, (jint*)v2JIntCArray, 0); // release resources
    (*env)->ReleaseIntArrayElements(env, v1JIntArray, (jint*)v1JIntCArray, 0); // release resources
}
