#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex4sv(JNIEnv *env, jobject object, jshortArray vJShortArray) {
    DPRINTF("glVertex4sv(%p);\n", vJShortArray);

    jshort *vJShortCArray = (*env)->GetShortArrayElements(env, vJShortArray, NULL);
    if (NULL == vJShortCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJShortArray);
    if (3 != length) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        static char s[256];
        sprintf(s, "You must pass exactly %d elements.", 4);
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    glVertex4sv((const GLshort*)vJShortCArray);

    (*env)->ReleaseShortArrayElements(env, vJShortArray, vJShortCArray, 0); // release resources
}
