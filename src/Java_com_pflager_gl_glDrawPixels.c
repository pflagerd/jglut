#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

int pixelDataTypeLength(int type) {
	switch (type) {

	case GL_UNSIGNED_BYTE:
		return 1; // unsigned 8-bit integer

	case GL_BYTE:
		return 1; // signed 8-bit integer

	case GL_BITMAP:
		return 1; //single bits in unsigned 8-bit integers

	case GL_UNSIGNED_SHORT:
		return 2; // unsigned 16-bit integer

	case GL_SHORT:
		return 2; // signed 16-bit integer

	case GL_UNSIGNED_INT:
		return 4; // unsigned 32-bit integer

	case GL_INT:
		return 4; //32-bit integer

	case GL_FLOAT:
		return 4; // single-precision floating-point

	case GL_UNSIGNED_BYTE_3_3_2:
		return 1; // unsigned 8-bit integer

	case GL_UNSIGNED_BYTE_2_3_3_REV:
		return 1; //unsigned 8-bit integer with reversed component ordering

	case GL_UNSIGNED_SHORT_5_6_5:
		return 1; //unsigned 16-bit integer

	case GL_UNSIGNED_SHORT_5_6_5_REV:
		return 2; // unsigned 16-bit integer with reversed component ordering

	case GL_UNSIGNED_SHORT_4_4_4_4:
		return 2; //unsigned 16-bit integer

	case GL_UNSIGNED_SHORT_4_4_4_4_REV:
		return 2; //unsigned 16-bit integer with reversed component ordering

	case GL_UNSIGNED_SHORT_5_5_5_1:
		return 2; // unsigned 16-bit integer

	case GL_UNSIGNED_SHORT_1_5_5_5_REV:
		return 2; //unsigned 16-bit integer with reversed component ordering

	case GL_UNSIGNED_INT_8_8_8_8:
		return 4; //unsigned 32-bit integer

	case GL_UNSIGNED_INT_8_8_8_8_REV:
		return 4; //unsigned 32-bit integer with reversed component ordering

	case GL_UNSIGNED_INT_10_10_10_2:
		return 4; // unsigned 32-bit integer

	case GL_UNSIGNED_INT_2_10_10_10_REV:
		return 4; //unsigned 32-bit integer with reversed component ordering

	default:
		return 0; // error
	}

}

JNIEXPORT void JNICALL Java_com_pflager_gl_glDrawPixels(JNIEnv *env, jobject object, jint widthJInt, jint heightJInt, jint formatJInt, jint typeJInt, jbyteArray pixelsJByteArray) {
	DPRINTF("glDrawPixels(%d, %d, %d, %d, %p);\n", widthJInt, heightJInt, formatJInt, typeJInt, pixelsJByteArray);

	if (pixelsJByteArray == NULL) {
		char s[256];
		sprintf(s, "Pass an array with at least %d elements.", pixelDataTypeLength(typeJInt) * widthJInt * heightJInt / 8);
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		(*env)->ThrowNew(env, illegalArgumentException, s);
		return;
	}

	jsize length = (*env)->GetArrayLength(env, pixelsJByteArray);
	if (length < pixelDataTypeLength(typeJInt) * widthJInt * heightJInt / 8) {
		char s[256];
		sprintf(s, "Pass an array with exactly %d elements.", pixelDataTypeLength(typeJInt) * widthJInt * heightJInt / 8);
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		(*env)->ThrowNew(env, illegalArgumentException, s);
		return;
	}

	jbyte* jbyteArrayElements = (*env)->GetByteArrayElements(env, pixelsJByteArray, NULL);

	glDrawPixels(widthJInt, heightJInt, formatJInt, typeJInt, jbyteArrayElements);

	(*env)->ReleaseByteArrayElements(env, pixelsJByteArray, jbyteArrayElements, 0); // release resources
}
