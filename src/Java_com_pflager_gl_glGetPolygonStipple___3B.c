#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glGetPolygonStipple___3B(JNIEnv *env, jobject object, jbyteArray maskJByteArray) {
    DPRINTF("glGetPolygonStipple(%p);\n", maskJByteArray);

    jbyte *maskJByteCArray = (*env)->GetByteArrayElements(env, maskJByteArray, NULL);
    if (NULL == maskJByteCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, maskJByteArray);
    if (length != 128) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 4 elements.");
        return;
    }

    GLubyte GLubyte_array[length];

    glGetPolygonStipple(GLubyte_array);

    (*env)->SetByteArrayRegion(env, maskJByteArray, 0 , length, (jbyte*)GLubyte_array);  // copy
    }
