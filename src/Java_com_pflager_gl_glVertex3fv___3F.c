#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex3fv___3F(JNIEnv *env, jobject object, jfloatArray vJFloatArray) {
    DPRINTF("glVertex3fv(%p);\n", vJFloatArray);

    if (vJFloatArray == NULL) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 3 elements.");
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJFloatArray);
    if (length != 3) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 3 elements.");
        return;
    }

    jfloat *jfloatArrayElements = (*env)->GetFloatArrayElements(env, vJFloatArray, NULL);

    glVertex3fv(jfloatArrayElements);

    (*env)->ReleaseFloatArrayElements(env, vJFloatArray, jfloatArrayElements, 0); // release resources
}
