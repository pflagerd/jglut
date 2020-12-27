#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexSubImage2D__IIIIIIII_3S(JNIEnv *env, jobject object, jint targetJInt, jint levelJInt, jint xoffsetJInt, jint yoffsetJInt, jint widthJInt, jint heightJInt, jint formatJInt, jint typeJInt, jshortArray pixelsJShortArray) {
    DPRINTF("glTexSubImage2D(%d, %d, %d, %d, %d, %d, %d, %d, %p);\n", targetJInt, levelJInt, xoffsetJInt, yoffsetJInt, widthJInt, heightJInt, formatJInt, typeJInt, pixelsJShortArray);

	if (pixelsJShortArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with at least %d elements.", widthJInt * heightJInt);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

	if (!(typeJInt == GL_UNSIGNED_SHORT_5_6_5 || typeJInt == GL_UNSIGNED_SHORT_4_4_4_4 || typeJInt == GL_UNSIGNED_SHORT_5_5_5_1)) {
        char s[256];
        sprintf(s, "This function overload only supports type in { GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_4_4_4_4 or GL_UNSIGNED_SHORT_5_5_5_1 }.");
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, pixelsJShortArray);
    if (length < widthJInt * heightJInt) {
        char s[256];
        sprintf(s, "Pass an array with at least %d elements.", widthJInt * heightJInt);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jshort* jshortArrayElements = (*env)->GetShortArrayElements(env, pixelsJShortArray, NULL);

    glTexSubImage2D(targetJInt, levelJInt, xoffsetJInt, yoffsetJInt, widthJInt, heightJInt, formatJInt, typeJInt, jshortArrayElements);

	(*env)->ReleaseShortArrayElements(env, pixelsJShortArray, jshortArrayElements, 0); // release resources
}
