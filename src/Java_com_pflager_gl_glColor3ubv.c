#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor3ubv(JNIEnv *env, jobject object, jbyteArray vJByteArray) {
    DPRINTF("glColor3ubv(%p);\n", vJByteArray);

	if (vJByteArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 3);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJByteArray);
    if (length != 3) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 3);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jbyte* jbyteArrayElements = (*env)->GetByteArrayElements(env, vJByteArray, NULL);

    glColor3ubv((const GLubyte*)jbyteArrayElements);

	(*env)->ReleaseByteArrayElements(env, vJByteArray, jbyteArrayElements, 0); // release resources
}
