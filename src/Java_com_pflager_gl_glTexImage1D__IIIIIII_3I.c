#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

extern int glTexImage1D_format_length(jint formatJInt);
extern jboolean in_int_array(int what, int array[], size_t array_length);

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexImage1D__IIIIIII_3I(JNIEnv *env, jobject object, jint targetJInt, jint levelJInt, jint internalFormatJInt, jint widthJInt, jint borderJInt, jint formatJInt, jint typeJInt, jintArray pixelsJIntArray) {
    DPRINTF("glTexImage1D(%d, %d, %d, %d, %d, %d, %d, %p);\n", targetJInt, levelJInt, internalFormatJInt, widthJInt, borderJInt, formatJInt, typeJInt, pixelsJIntArray);

	if (pixelsJIntArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", widthJInt * glTexImage1D_format_length(formatJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

	int types[] = { GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_INT_10_10_10_2, GL_UNSIGNED_INT_2_10_10_10_REV };
	if (!in_int_array(typeJInt, types, sizeof(types)/sizeof(*types))) {
		char s[256];
		sprintf(s, "This function overload only supports INT types.");
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		(*env)->ThrowNew(env, illegalArgumentException, s);
		return;
	}

    jsize length = (*env)->GetArrayLength(env, pixelsJIntArray);
    if (length != widthJInt * glTexImage1D_format_length(formatJInt)) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", widthJInt * glTexImage1D_format_length(formatJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jint* jintArrayElements = (*env)->GetIntArrayElements(env, pixelsJIntArray, NULL);

    glTexImage1D(targetJInt, levelJInt, internalFormatJInt, widthJInt, borderJInt, formatJInt, typeJInt, jintArrayElements);

	(*env)->ReleaseIntArrayElements(env, pixelsJIntArray, jintArrayElements, 0); // release resources
}
