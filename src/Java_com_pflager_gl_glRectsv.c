#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRectsv(JNIEnv *env, jobject object, jshortArray v1JShortArray, jshortArray v2JShortArray) {
    DPRINTF("glRectsv(%p, %p);\n", v1JShortArray, v2JShortArray);

    const jshort *v1JShortCArray = (*env)->GetShortArrayElements(env, v1JShortArray, NULL);
    if (NULL == v1JShortCArray) {
    	return;
    }
    jsize length = (*env)->GetArrayLength(env, v1JShortArray);
    if (length != 2) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "You must pass exactly 2 elements for v1");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    const jshort *v2JShortCArray = (*env)->GetShortArrayElements(env, v2JShortArray, NULL);
    if (NULL == v2JShortCArray) {
    	return;
    }

    length = (*env)->GetArrayLength(env, v2JShortArray);
    if (length != 2) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "You must pass exactly 2 elements for v2");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    glRectsv(v1JShortCArray, v2JShortCArray);

    (*env)->ReleaseShortArrayElements(env, v2JShortArray, (short*)v2JShortCArray, 0); // release resources
    (*env)->ReleaseShortArrayElements(env, v1JShortArray, (short*)v1JShortCArray, 0); // release resources
}
