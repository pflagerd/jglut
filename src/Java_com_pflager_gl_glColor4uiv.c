#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor4uiv(JNIEnv *env, jobject object, jintArray vJIntArray) {
    DPRINTF("glColor4uiv(%p);\n", vJIntArray);

	if (vJIntArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 4);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJIntArray);
    if (length != 4) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 4);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jint* jintArrayElements = (*env)->GetIntArrayElements(env, vJIntArray, NULL);

    glColor4uiv(jintArrayElements);

	(*env)->ReleaseIntArrayElements(env, vJIntArray, jintArrayElements, 0); // release resources
}
