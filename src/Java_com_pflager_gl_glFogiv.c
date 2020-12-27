#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glFogiv(JNIEnv *env, jobject object, jint pnameJInt, jintArray paramsJIntArray) {
    DPRINTF("glFogiv(%d, %p);\n", pnameJInt, paramsJIntArray);

	if (paramsJIntArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", array_length_from_pname(pnameJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, paramsJIntArray);
    if (length != array_length_from_pname(pnameJInt)) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", array_length_from_pname(pnameJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jint* jintArrayElements = (*env)->GetIntArrayElements(env, paramsJIntArray, NULL);

    glFogiv(pnameJInt, jintArrayElements);

	(*env)->ReleaseIntArrayElements(env, paramsJIntArray, jintArrayElements, 0); // release resources
}
