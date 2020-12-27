#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexGeniv__II_3S(JNIEnv *env, jobject object, jint coordJInt, jint pnameJInt, jshortArray paramsJShortArray) {
    DPRINTF("glTexGeniv(%d, %d, %p);\n", coordJInt, pnameJInt, paramsJShortArray);

	if (paramsJShortArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", array_length_from_pname(pnameJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, paramsJShortArray);
    if (length != array_length_from_pname(pnameJInt)) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", array_length_from_pname(pnameJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jshort* jshortArrayElements = (*env)->GetShortArrayElements(env, paramsJShortArray, NULL);

    GLint glintArray[length];

    for (int i = 0; i < length; i++) {
    	glintArray[i] = jshortArrayElements[i];
    }

    glTexGeniv(coordJInt, pnameJInt, glintArray);

	(*env)->ReleaseShortArrayElements(env, paramsJShortArray, jshortArrayElements, 0); // release resources
}
