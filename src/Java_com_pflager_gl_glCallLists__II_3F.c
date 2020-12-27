#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glCallLists__II_3F(JNIEnv *env, jobject object, jint nJInt, jint typeJInt, jfloatArray listsJFloatArray) {
    DPRINTF("glCallLists(%d, %d, %p);\n", nJInt, typeJInt, listsJFloatArray);

    if (typeJInt != GL_FLOAT) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, "Passing an array of float only makes sense for type == GL_FLOAT");
    	return;
    }

	if (listsJFloatArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", nJInt);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, listsJFloatArray);
    if (length != nJInt) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", nJInt);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jfloat* jfloatArrayElements = (*env)->GetFloatArrayElements(env, listsJFloatArray, NULL);

    glCallLists(nJInt, typeJInt, jfloatArrayElements);

	(*env)->ReleaseFloatArrayElements(env, listsJFloatArray, jfloatArrayElements, 0); // release resources
}
