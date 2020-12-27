#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jdoubleArray JNICALL Java_com_pflager_gl_glGetDoublev__I(JNIEnv *env, jobject object, jint pname) {
    DPRINTF("glGetDoublev(%d);\n", pname);

    jsize length = array_length_from_pname(pname);
    if (length == 0) {
        jclass notImplementedException = (*env)->FindClass(env, "com/pflager/glut$NotImplementedException");
        DPRINTF("notImplementedException == %p\n", notImplementedException);
        static char s[128];
        sprintf(s, "pname %d, not supported yet", pname);
        (*env)->ThrowNew(env, notImplementedException, s);
        return NULL;
    }

    double double_array[length];

    glGetDoublev(pname, double_array);

    jdoubleArray jDoubleArray = (*env)->NewDoubleArray(env, length);  // allocate
    if (NULL == jDoubleArray) {
    	return NULL;
    }

    (*env)->SetDoubleArrayRegion(env, jDoubleArray, 0 , length, double_array);  // copy

    return jDoubleArray;
 }
