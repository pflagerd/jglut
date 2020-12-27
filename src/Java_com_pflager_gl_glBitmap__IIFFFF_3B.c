#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glBitmap__IIFFFF_3B(JNIEnv *env, jobject object, jint widthJInt, jint heightJInt, jfloat xorigJFloat, jfloat yorigJFloat, jfloat xmoveJFloat, jfloat ymoveJFloat, jbyteArray bitmapJByteArray) {
    DPRINTF("glBitmap(%d, %d, %.8g%sf, %.8g%sf, %.8g%sf, %.8g%sf, %p);\n", widthJInt, heightJInt, xorigJFloat, xorigJFloat == (int)xorigJFloat ? ".0" : "", yorigJFloat, yorigJFloat == (int)yorigJFloat ? ".0" : "", xmoveJFloat, xmoveJFloat == (int)xmoveJFloat ? ".0" : "", ymoveJFloat, ymoveJFloat == (int)ymoveJFloat ? ".0" : "", bitmapJByteArray);

	if (bitmapJByteArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with at least %d elements.", widthJInt * heightJInt / 8);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, bitmapJByteArray);
    if (length < widthJInt * heightJInt / 8) {
        char s[256];
        sprintf(s, "Pass an array with at least %d elements.", widthJInt * heightJInt / 8);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jbyte* jbyteArrayElements = (*env)->GetByteArrayElements(env, bitmapJByteArray, NULL);

    glBitmap(widthJInt, heightJInt, xorigJFloat, yorigJFloat, xmoveJFloat, ymoveJFloat, (const GLubyte*)jbyteArrayElements);

	(*env)->ReleaseByteArrayElements(env, bitmapJByteArray, jbyteArrayElements, 0); // release resources
}
