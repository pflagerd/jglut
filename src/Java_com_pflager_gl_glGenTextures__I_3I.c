#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glGenTextures__I_3I(JNIEnv *env, jobject object, jint nJInt, jintArray texturesJIntArray) {
    DPRINTF("glGenTextures(%d, %p);\n", nJInt, texturesJIntArray);

    jint *texturesJIntCArray = (*env)->GetIntArrayElements(env, texturesJIntArray, NULL);
    if (NULL == texturesJIntCArray) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with at least one element.");
        return;
    }

    if (nJInt <= 0) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "You should pass n >= 0.");
        return;
    }

    jsize length = (*env)->GetArrayLength(env, texturesJIntArray);
    if (length == 0) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with at least one elements.");
        return;
    }

    GLuint int_array[length];

    glGenTextures(nJInt, int_array);

    for (int i = 0; i < length; i++) {
    	texturesJIntCArray[i] = int_array[i];
    }

    (*env)->SetIntArrayRegion(env, texturesJIntArray, 0 , length, texturesJIntCArray);  // copy

    (*env)->ReleaseIntArrayElements(env, texturesJIntArray, texturesJIntCArray, 0); // release resources
}
