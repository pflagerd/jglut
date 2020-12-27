#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRasterPos2iv(JNIEnv *env, jobject object, jintArray vJIntArray) {
    DPRINTF("glRasterPos2iv(%p);\n", vJIntArray);

	if (vJIntArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 2);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJIntArray);
    if (length != 2) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 2);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jint* jintArrayElements = (*env)->GetIntArrayElements(env, vJIntArray, NULL);

    glRasterPos2iv(jintArrayElements);

	(*env)->ReleaseIntArrayElements(env, vJIntArray, jintArrayElements, 0); // release resources
}
