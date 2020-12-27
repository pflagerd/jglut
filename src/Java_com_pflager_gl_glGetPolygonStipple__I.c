#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jintArray JNICALL Java_com_pflager_gl_glGetPolygonStipple__I(JNIEnv *env, jobject object, jint typeDummyJInt) {
    DPRINTF("glGetPolygonStipple(%d);\n", typeDummyJInt);

    jsize length = 128;

    GLubyte GLubyte_array[length];

    glGetPolygonStipple(GLubyte_array);

    jintArray jIntArray = (*env)->NewIntArray(env, length);  // allocate
    if (NULL == jIntArray) {
    	return NULL;
    }

    GLuint GLuint_array[length];

    for (int i = 0; i < length; i++) {
    	GLuint_array[i] = GLubyte_array[i];
    }

    (*env)->SetIntArrayRegion(env, jIntArray, 0 , length, (jint*)GLuint_array);  // copy

    return jIntArray;
}
