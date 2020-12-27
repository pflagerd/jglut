#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos4fv___3F(JNIEnv *env, jobject object, jfloatArray vJFloatArray) {
    DPRINTF("glRasterPos4fv(%p);\n", vJFloatArray);

	if (vJFloatArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 4);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJFloatArray);
    if (length != 4) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 4);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jfloat* jfloatArrayElements = (*env)->GetFloatArrayElements(env, vJFloatArray, NULL);

    glRasterPos4fv(jfloatArrayElements);

	(*env)->ReleaseFloatArrayElements(env, vJFloatArray, jfloatArrayElements, 0); // release resources
}
