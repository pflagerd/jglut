#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glColor4ubv(JNIEnv *env, jobject object, jbyteArray vJByteArray) {
    DPRINTF("glColor4ubv(%p);\n", vJByteArray);

	if (vJByteArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 4);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJByteArray);
    if (length != 4) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 4);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jbyte* jbyteArrayElements = (*env)->GetByteArrayElements(env, vJByteArray, NULL);

    glColor4ubv((const GLubyte *)jbyteArrayElements);

	(*env)->ReleaseByteArrayElements(env, vJByteArray, jbyteArrayElements, 0); // release resources
}
