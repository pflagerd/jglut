#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glBitmap__IIFFFF_3S(JNIEnv *env, jobject object, jint widthJInt, jint heightJInt, jfloat xorigJFloat, jfloat yorigJFloat, jfloat xmoveJFloat, jfloat ymoveJFloat, jshortArray bitmapJShortArray) {
    DPRINTF("glBitmap(%d, %d, %.8g%sf, %.8g%sf, %.8g%sf, %.8g%sf, %p);\n", widthJInt, heightJInt, xorigJFloat, xorigJFloat == (int)xorigJFloat ? ".0" : "", yorigJFloat, yorigJFloat == (int)yorigJFloat ? ".0" : "", xmoveJFloat, xmoveJFloat == (int)xmoveJFloat ? ".0" : "", ymoveJFloat, ymoveJFloat == (int)ymoveJFloat ? ".0" : "", bitmapJShortArray);

	if (bitmapJShortArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with at least %d elements.", widthJInt * heightJInt / 8);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, bitmapJShortArray);
    if (length < widthJInt * heightJInt / 8) {
        char s[256];
        sprintf(s, "Pass an array with at least %d elements.", widthJInt * heightJInt / 8);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jshort* jshortArrayElements = (*env)->GetShortArrayElements(env, bitmapJShortArray, NULL);

    GLubyte glubyteArray[length];

    for (int i = 0; i < length; i++) {
    	glubyteArray[i] = (GLubyte)jshortArrayElements[i];
    }

    glBitmap(widthJInt, heightJInt, xorigJFloat, yorigJFloat, xmoveJFloat, ymoveJFloat, (const GLubyte*)glubyteArray);

	(*env)->ReleaseShortArrayElements(env, bitmapJShortArray, jshortArrayElements, 0); // release resources
}
