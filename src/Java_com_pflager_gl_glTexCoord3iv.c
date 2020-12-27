#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexCoord3iv(JNIEnv *env, jobject object, jintArray vJIntArray) {
    DPRINTF("glTexCoord3iv(%p);\n", vJIntArray);

	if (vJIntArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 3);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJIntArray);
    if (length != 3) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 3);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jint* jintArrayElements = (*env)->GetIntArrayElements(env, vJIntArray, NULL);

    glTexCoord3iv(jintArrayElements);

	(*env)->ReleaseIntArrayElements(env, vJIntArray, jintArrayElements, 0); // release resources
}
