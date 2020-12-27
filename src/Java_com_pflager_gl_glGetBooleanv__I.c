#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jbooleanArray JNICALL Java_com_pflager_gl_glGetBooleanv__I(JNIEnv *env, jobject object, jint pnameJInt) {
    DPRINTF("glGetBooleanv(%d);\n", pnameJInt);

    jsize length = array_length_from_pname(pnameJInt);
    if (length == 0) {
        jclass notImplementedException = (*env)->FindClass(env, "com/pflager/glut$NotImplementedException");
        DPRINTF("notImplementedException == %p\n", notImplementedException);
        static char s[128];
        sprintf(s, "pname %d, not supported yet", pnameJInt);
        (*env)->ThrowNew(env, notImplementedException, s);
        return NULL;
    }

    jboolean boolean_array[length];

    glGetBooleanv(pnameJInt, boolean_array);

    jbooleanArray jBooleanArray = (*env)->NewBooleanArray(env, length);  // allocate
    if (NULL == jBooleanArray) {
    	return NULL;
    }

    (*env)->SetBooleanArrayRegion(env, jBooleanArray, 0 , length, boolean_array);  // copy

    return jBooleanArray;
}
