#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

extern int glTexImage1D_format_length(jint formatJInt);
extern jboolean in_int_array(int what, int array[], size_t array_length);

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexImage1D__IIIIIII_3B(JNIEnv *env, jobject object, jint targetJInt, jint levelJInt, jint internalFormatJInt, jint widthJInt, jint borderJInt, jint formatJInt, jint typeJInt, jbyteArray pixelsJByteArray) {
    DPRINTF("glTexImage1D(%d, %d, %d, %d, %d, %d, %d, %p);\n", targetJInt, levelJInt, internalFormatJInt, widthJInt, borderJInt, formatJInt, typeJInt, pixelsJByteArray);

	if (pixelsJByteArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", widthJInt * glTexImage1D_format_length(formatJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

	int types[] = { GL_UNSIGNED_BYTE, GL_BYTE, GL_BITMAP, GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_2_3_3_REV };
	if (!in_int_array(typeJInt, types, sizeof(types)/sizeof(*types))) {
		char s[256];
		sprintf(s, "This function overload only supports BYTE types.");
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		(*env)->ThrowNew(env, illegalArgumentException, s);
		return;
	}

    jsize length = (*env)->GetArrayLength(env, pixelsJByteArray);
    if (length != widthJInt * glTexImage1D_format_length(formatJInt)) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", widthJInt * glTexImage1D_format_length(formatJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jbyte* jbyteArrayElements = (*env)->GetByteArrayElements(env, pixelsJByteArray, NULL);

    glTexImage1D(targetJInt, levelJInt, internalFormatJInt, widthJInt, borderJInt, formatJInt, typeJInt, jbyteArrayElements);

	(*env)->ReleaseByteArrayElements(env, pixelsJByteArray, jbyteArrayElements, 0); // release resources
}
