#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jintArray JNICALL Java_com_pflager_gl_glGetIntegerv__I(JNIEnv *env, jobject object, jint pname) {
    DPRINTF("glGetIntegerv(%d);\n", pname);

    jsize length = array_length_from_pname(pname);
    if (length == 0) {
        jclass notImplementedException = (*env)->FindClass(env, "com/pflager/glut$NotImplementedException");
        DPRINTF("notImplementedException == %p\n", notImplementedException);
        static char s[128];
        sprintf(s, "pname %d, not supported yet", pname);
        (*env)->ThrowNew(env, notImplementedException, s);
        return NULL;
    }

    int int_array[length];

    glGetIntegerv(pname, int_array);

    jintArray jIntArray = (*env)->NewIntArray(env, length);  // allocate
    if (NULL == jIntArray) {
    	return NULL;
    }

    (*env)->SetIntArrayRegion(env, jIntArray, 0 , length, int_array);  // copy

    return jIntArray;
}
