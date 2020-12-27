#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex4dv(JNIEnv *env, jobject object, jdoubleArray vJDoubleArray) {
    DPRINTF("glVertex4dv(%p);\n", vJDoubleArray);

    jdouble *vJDoubleCArray = (*env)->GetDoubleArrayElements(env, vJDoubleArray, NULL);
    if (NULL == vJDoubleCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJDoubleArray);
    if (3 != length) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        static char s[256];
        sprintf(s, "You must pass exactly %d elements.", 4);
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    glVertex4dv((const GLdouble*)vJDoubleCArray);

    (*env)->ReleaseDoubleArrayElements(env, vJDoubleArray, vJDoubleCArray, 0); // release resources
}
