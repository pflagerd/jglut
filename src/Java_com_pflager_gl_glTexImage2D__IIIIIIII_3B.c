#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexImage2D__IIIIIIII_3B(JNIEnv *env, jobject object, jint targetJInt, jint levelJInt, jint internalFormatJInt, jint widthJInt, jint heightJInt, jint borderJInt, jint formatJInt, jint typeJInt, jbyteArray pixelsJByteArray) {
    DPRINTF("glTexImage2D(%d, %d, %d, %d, %d, %d, %d, %d, %p);\n", targetJInt, levelJInt, internalFormatJInt, widthJInt, heightJInt, borderJInt, formatJInt, typeJInt, pixelsJByteArray);

	if (pixelsJByteArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with at least %d elements.", widthJInt * heightJInt);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

	if (typeJInt != GL_UNSIGNED_BYTE) {
        char s[256];
        sprintf(s, "This function overload only supports type == GL_UNSIGNED_BYTE.");
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, pixelsJByteArray);
    if (length < widthJInt * heightJInt) {
        char s[256];
        sprintf(s, "Pass an array with at least %d elements.", widthJInt * heightJInt);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jbyte* jbyteArrayElements = (*env)->GetByteArrayElements(env, pixelsJByteArray, NULL);

    glTexImage2D(targetJInt, levelJInt, internalFormatJInt, widthJInt, heightJInt, borderJInt, formatJInt, typeJInt, jbyteArrayElements);

	(*env)->ReleaseByteArrayElements(env, pixelsJByteArray, jbyteArrayElements, 0); // release resources
}
