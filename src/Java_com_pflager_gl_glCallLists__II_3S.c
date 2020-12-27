#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glCallLists__II_3S(JNIEnv *env, jobject object, jint nJInt, jint typeJInt, jshortArray listsJShortArray) {
    DPRINTF("glCallLists(%d, %d, %p);\n", nJInt, typeJInt, listsJShortArray);

    if (typeJInt != GL_SHORT && typeJInt != GL_UNSIGNED_SHORT) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, "Passing an array of short only makes sense for type == GL_SHORT or type == GL_UNSIGNED_SHORT");
    	return;
    }

	if (listsJShortArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", typeJInt);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, listsJShortArray);
    if (length != nJInt) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", typeJInt);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jshort* jshortArrayElements = (*env)->GetShortArrayElements(env, listsJShortArray, NULL);

    glCallLists(nJInt, typeJInt, jshortArrayElements);

	(*env)->ReleaseShortArrayElements(env, listsJShortArray, jshortArrayElements, 0); // release resources
}
