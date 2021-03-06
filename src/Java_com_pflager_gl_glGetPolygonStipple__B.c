#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jbyteArray JNICALL Java_com_pflager_gl_glGetPolygonStipple__B(JNIEnv *env, jobject object, jbyte byteDummyJByte) {
    DPRINTF("glGetPolygonStipple(%d);\n", byteDummyJByte);

    jsize length = 128;

    GLubyte GLubyte_array[length];

    glGetPolygonStipple(GLubyte_array);

    jbyteArray jByteArray = (*env)->NewByteArray(env, length);  // allocate
    if (NULL == jByteArray) {
    	return NULL;
    }

    (*env)->SetByteArrayRegion(env, jByteArray, 0 , length, (jbyte*)GLubyte_array);  // copy

    return jByteArray;
}
