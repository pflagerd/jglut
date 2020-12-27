#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPolygonStipple___3B(JNIEnv *env, jobject object, jbyteArray maskJByteArray) {
    DPRINTF("glPolygonStipple(%p);\n", maskJByteArray);

	if (maskJByteArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 128);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, maskJByteArray);
    if (length != 128) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 128);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jbyte* jbyteArrayElements = (*env)->GetByteArrayElements(env, maskJByteArray, NULL);

    glPolygonStipple((const GLubyte*)jbyteArrayElements);

	(*env)->ReleaseByteArrayElements(env, maskJByteArray, jbyteArrayElements, 0); // release resources
}
