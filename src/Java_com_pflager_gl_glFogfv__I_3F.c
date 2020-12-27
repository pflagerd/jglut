#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glFogfv__I_3F(JNIEnv *env, jobject object, jint pnameJInt, jfloatArray paramsJFloatArray) {
    DPRINTF("glFogfv(%d, %p);\n", pnameJInt, paramsJFloatArray);

	if (paramsJFloatArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", array_length_from_pname(pnameJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, paramsJFloatArray);
    if (length != array_length_from_pname(pnameJInt)) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", array_length_from_pname(pnameJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jfloat* jfloatArrayElements = (*env)->GetFloatArrayElements(env, paramsJFloatArray, NULL);

    glFogfv(pnameJInt, jfloatArrayElements);

	(*env)->ReleaseFloatArrayElements(env, paramsJFloatArray, jfloatArrayElements, 0); // release resources
}
