#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor3sv(JNIEnv *env, jobject object, jshortArray vJShortArray) {
    DPRINTF("glColor3sv(%p);\n", vJShortArray);

	if (vJShortArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 3);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJShortArray);
    if (length != 3) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 3);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jshort* jshortArrayElements = (*env)->GetShortArrayElements(env, vJShortArray, NULL);

    glColor3sv(jshortArrayElements);

	(*env)->ReleaseShortArrayElements(env, vJShortArray, jshortArrayElements, 0); // release resources
}
