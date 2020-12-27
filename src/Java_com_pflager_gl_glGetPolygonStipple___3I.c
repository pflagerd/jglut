#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glGetPolygonStipple___3I(JNIEnv *env, jobject object, jintArray maskJIntArray) {
    DPRINTF("glGetPolygonStipple(%p);\n", maskJIntArray);

    jint *maskJIntCArray = (*env)->GetIntArrayElements(env, maskJIntArray, NULL);
    if (NULL == maskJIntCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, maskJIntArray);
    if (length != 128) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 4 elements.");
        return;
    }

    GLubyte GLubyte_array[length];

    glGetPolygonStipple(GLubyte_array);

    GLuint GLuint_array[length];

    for (int i = 0; i < length; i++) {
    	GLuint_array[i] = GLubyte_array[i];
    }

    (*env)->SetIntArrayRegion(env, maskJIntArray, 0 , length, (jint*)GLuint_array);  // copy
}
