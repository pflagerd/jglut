#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glCallLists__II_3I(JNIEnv *env, jobject object, jint nJInt, jint typeJInt, jintArray listsJIntArray) {
    DPRINTF("glCallLists(%d, %d, %p);\n", nJInt, typeJInt, listsJIntArray);

    if (typeJInt != GL_INT && typeJInt != GL_UNSIGNED_INT) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, "Passing an array of int only makes sense for type == GL_INT or type == GL_UNSIGNED_INT");
    	return;
    }

	if (listsJIntArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", nJInt);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, listsJIntArray);
    if (length != nJInt) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", nJInt);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jint* jintArrayElements = (*env)->GetIntArrayElements(env, listsJIntArray, NULL);

    glCallLists(nJInt, typeJInt, jintArrayElements);

	(*env)->ReleaseIntArrayElements(env, listsJIntArray, jintArrayElements, 0); // release resources
}
