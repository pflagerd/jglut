#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glReadPixels__IIIIII_3B(JNIEnv *env, jobject object, jint x, jint y, jint width, jint height, jint format, jint type, jbyteArray pixelsJByteArray) {
    DPRINTF("glReadPixels(%d, %d, %d, %d, %d, %d, %p);\n", x, y, width, height, format, type, pixelsJByteArray);
    jbyte *pixelsJByteCArray = (*env)->GetByteArrayElements(env, pixelsJByteArray, NULL);
    if (NULL == pixelsJByteCArray) {
    	return;
    }

    if (GL_RGBA != format || type != GL_UNSIGNED_BYTE) {
        jclass notImplementedException = (*env)->FindClass(env, "com/pflager/glut$NotImplementedException");
        DPRINTF("notImplementedException == %p\n", notImplementedException);
        (*env)->ThrowNew(env, notImplementedException, "glReadPixels() currently only understands format == GL_RGBA and type == GL_UNSIGNED_BYTE");
        return;
    }

    jsize length = (*env)->GetArrayLength(env, pixelsJByteArray);
    if (GL_RGBA == format && type == GL_UNSIGNED_BYTE && length != (int)width * (int)height * 4) { // TODO: DPP: 190331T182100: Need a bunch of these checks.
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 4 elements.");
        return;
    }

    char byte_array[length];

    glReadPixels(x, y, width, height, format, type, byte_array);

    for (int i = 0; i < length; i++) {
    	pixelsJByteCArray[i] = byte_array[i];
    }

    (*env)->SetByteArrayRegion(env, pixelsJByteArray, 0 , length, pixelsJByteCArray);  // copy

    (*env)->ReleaseByteArrayElements(env, pixelsJByteArray, pixelsJByteCArray, 0); // release resources
}
