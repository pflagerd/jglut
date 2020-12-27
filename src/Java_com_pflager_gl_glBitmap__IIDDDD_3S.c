#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glBitmap__IIDDDD_3S(JNIEnv *env, jobject object, jint widthJInt, jint heightJInt, jdouble xorigJDouble, jdouble yorigJDouble, jdouble xmoveJDouble, jdouble ymoveJDouble, jshortArray bitmapJShortArray) {
    Java_com_pflager_gl_glBitmap__IIFFFF_3S(env, object, widthJInt, heightJInt, (float)xorigJDouble, (float)yorigJDouble, (float)xmoveJDouble, (float)ymoveJDouble, bitmapJShortArray);
}
