#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glClipPlane(JNIEnv *env, jobject object, jint plane, jdoubleArray equationJDoubleArray) {
    DPRINTF("glClipPlane(%d, %p);\n", plane, equationJDoubleArray);

    jdouble *equationJDoubleCArray = (*env)->GetDoubleArrayElements(env, equationJDoubleArray, NULL);
    if (NULL == equationJDoubleCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, equationJDoubleArray);
    if (length != 4) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 4 elements.");
        return;
    }

    glClipPlane(plane, equationJDoubleCArray);

    (*env)->ReleaseDoubleArrayElements(env, equationJDoubleArray, equationJDoubleCArray, 0); // release resources
}
