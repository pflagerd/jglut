#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex3sv(JNIEnv *env, jobject object, jshortArray vJShortArray) {
    DPRINTF("glVertex3sv(%p);\n", vJShortArray);

    jshort *vJShortCArray = (*env)->GetShortArrayElements(env, vJShortArray, NULL);
    if (NULL == vJShortCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJShortArray);
    if (3 != length) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        static char s[256];
        sprintf(s, "You must pass exactly %d elements.", 3);
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    glVertex3sv((const GLshort*)vJShortCArray);

    (*env)->ReleaseShortArrayElements(env, vJShortArray, vJShortCArray, 0); // release resources
}
