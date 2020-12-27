#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

int glTexImage1D_format_length(jint formatJInt) {
	switch (formatJInt) {
	case GL_LUMINANCE_ALPHA:
		return 2;

	case GL_RGB:
	case GL_BGR:
		return 3;

	case GL_RGBA:
	case GL_BGRA:
		return 4;

	case GL_DEPTH_COMPONENT:
	case GL_LUMINANCE:
	case GL_INTENSITY:
	case GL_ALPHA:
	case GL_BLUE:
	case GL_GREEN:
	case GL_RED:
	case GL_COLOR_INDEX:
	default:
		return 1;
	}
}

jboolean in_int_array(int what, int array[], size_t array_length) {
	for (int i = 0; i < array_length; i++) {
		if (what == array[i]) {
			return 1;
		}
	}
	return 0;
}

JNIEXPORT void JNICALL Java_com_pflager_gl_glTexImage1D__IIIIIII_3S(JNIEnv *env, jobject object, jint targetJInt, jint levelJInt, jint internalFormatJInt, jint widthJInt, jint borderJInt, jint formatJInt, jint typeJInt, jshortArray pixelsJShortArray) {
	DPRINTF("glTexImage1D(%d, %d, %d, %d, %d, %d, %d, %p);\n", targetJInt, levelJInt, internalFormatJInt, widthJInt, borderJInt, formatJInt, typeJInt, pixelsJShortArray);

	if (targetJInt != GL_PROXY_TEXTURE_1D) {
		if (pixelsJShortArray == NULL) {
			char s[256];
			sprintf(s, "Pass an array with exactly %d elements.", widthJInt * glTexImage1D_format_length(formatJInt));
			jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
			(*env)->ThrowNew(env, illegalArgumentException, s);
			return;
		}

		int types[] = { GL_UNSIGNED_SHORT, GL_SHORT, GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_5_6_5_REV, GL_UNSIGNED_SHORT_4_4_4_4, GL_UNSIGNED_SHORT_4_4_4_4_REV, GL_UNSIGNED_SHORT_5_5_5_1, GL_UNSIGNED_SHORT_1_5_5_5_REV};
		if (!in_int_array(typeJInt, types, sizeof(types)/sizeof(*types))) {
			char s[256];
			sprintf(s, "This function overload only supports SHORT types.");
			jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
			(*env)->ThrowNew(env, illegalArgumentException, s);
			return;
		}

		jsize length = (*env)->GetArrayLength(env, pixelsJShortArray);
		if (length != widthJInt * glTexImage1D_format_length(formatJInt)) {
			char s[256];
			sprintf(s, "Pass an array with exactly %d elements.", widthJInt * glTexImage1D_format_length(formatJInt));
			jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
			(*env)->ThrowNew(env, illegalArgumentException, s);
			return;
		}
	}

	jshort* jshortArrayElements = (*env)->GetShortArrayElements(env, pixelsJShortArray, NULL);

	glTexImage1D(targetJInt, levelJInt, internalFormatJInt, widthJInt, borderJInt, formatJInt, typeJInt, jshortArrayElements);

	(*env)->ReleaseShortArrayElements(env, pixelsJShortArray, jshortArrayElements, 0); // release resources
}
