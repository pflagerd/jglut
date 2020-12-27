#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

extern int glTexImage1D_format_length(jint formatJInt);

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexImage1D__IIIIIII_3F(JNIEnv *env, jobject object, jint targetJInt, jint levelJInt, jint internalFormatJInt, jint widthJInt, jint borderJInt, jint formatJInt, jint typeJInt, jfloatArray pixelsJFloatArray) {
    DPRINTF("glTexImage1D(%d, %d, %d, %d, %d, %d, %d, %p);\n", targetJInt, levelJInt, internalFormatJInt, widthJInt, borderJInt, formatJInt, typeJInt, pixelsJFloatArray);

	if (pixelsJFloatArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", widthJInt * glTexImage1D_format_length(formatJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

	if (typeJInt == GL_FLOAT) {
		char s[256];
		sprintf(s, "This function overload only supports SHORT types.");
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		(*env)->ThrowNew(env, illegalArgumentException, s);
		return;
	}

    jsize length = (*env)->GetArrayLength(env, pixelsJFloatArray);
    if (length != widthJInt * glTexImage1D_format_length(formatJInt)) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", widthJInt * glTexImage1D_format_length(formatJInt));
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jfloat* jfloatArrayElements = (*env)->GetFloatArrayElements(env, pixelsJFloatArray, NULL);

    glTexImage1D(targetJInt, levelJInt, internalFormatJInt, widthJInt, borderJInt, formatJInt, typeJInt, jfloatArrayElements);

	(*env)->ReleaseFloatArrayElements(env, pixelsJFloatArray, jfloatArrayElements, 0); // release resources
}
