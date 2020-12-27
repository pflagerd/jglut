#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glLightiv(JNIEnv *env, jobject object, jint lightJInt, jint pnameJInt, jintArray paramsJIntArray) {
    DPRINTF("glLightiv(%d, %d, %p);\n", lightJInt, pnameJInt, paramsJIntArray);

    jint *paramsJIntCArray = (*env)->GetIntArrayElements(env, paramsJIntArray, NULL);
    if (NULL == paramsJIntCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, paramsJIntArray);
    if (array_length_from_pname(pnameJInt) != length) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        static char s[256];
        sprintf(s, "glLightfv(int light, int pname, Int[] params): You must pass exactly %d elements for pname == %d", length, pnameJInt);
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    glLightiv(lightJInt, pnameJInt, paramsJIntCArray);

    (*env)->ReleaseIntArrayElements(env, paramsJIntArray, paramsJIntCArray, 0); // release resources
}
