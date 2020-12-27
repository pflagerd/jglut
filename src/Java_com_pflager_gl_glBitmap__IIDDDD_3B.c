#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glBitmap__IIDDDD_3B(JNIEnv *env, jobject object, jint widthJInt, jint heightJInt, jdouble xorigJDouble, jdouble yorigJDouble, jdouble xmoveJDouble, jdouble ymoveJDouble, jbyteArray bitmapJByteArray) {
    Java_com_pflager_gl_glBitmap__IIFFFF_3B(env, object, widthJInt, heightJInt, (float)xorigJDouble, (float)yorigJDouble, (float)xmoveJDouble, (float)ymoveJDouble, bitmapJByteArray);
}
