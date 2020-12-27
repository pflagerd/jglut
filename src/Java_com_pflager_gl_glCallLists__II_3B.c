#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glCallLists__II_3B(JNIEnv *env, jobject object, jint nJInt, jint typeJInt, jbyteArray listsJByteArray) {
    DPRINTF("glCallLists(%d, %d, %p);\n", nJInt, typeJInt, listsJByteArray);

    // TODO: Implement other sizes besides GL_BYTE and GL_UNSIGNED_BYTE
    if (typeJInt != GL_BYTE && typeJInt != GL_UNSIGNED_BYTE) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, "Only type == GL_BYTE or type == GL_UNSIGNED_BYTE allowed.");
    	return;
    }

	if (listsJByteArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", typeJInt);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, listsJByteArray);
    if (length != nJInt) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", typeJInt);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jbyte* jbyteArrayElements = (*env)->GetByteArrayElements(env, listsJByteArray, NULL);

    glCallLists(nJInt, typeJInt, jbyteArrayElements);

	(*env)->ReleaseByteArrayElements(env, listsJByteArray, jbyteArrayElements, 0); // release resources
}
