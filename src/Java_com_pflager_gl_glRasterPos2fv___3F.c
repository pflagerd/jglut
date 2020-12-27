#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos2fv___3F(JNIEnv *env, jobject object, jfloatArray vJFloatArray) {
    DPRINTF("glRasterPos2fv(%p);\n", vJFloatArray);

	if (vJFloatArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 2);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJFloatArray);
    if (length != 2) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 2);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jfloat* jfloatArrayElements = (*env)->GetFloatArrayElements(env, vJFloatArray, NULL);

    glRasterPos2fv(jfloatArrayElements);

	(*env)->ReleaseFloatArrayElements(env, vJFloatArray, jfloatArrayElements, 0); // release resources
}
