#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jfloatArray JNICALL Java_com_pflager_gl_glGetFloatv__I(JNIEnv *env, jobject object, jint pname) {
    DPRINTF("glGetFloatv(%d);\n", pname);

    jsize length = array_length_from_pname(pname);
    if (length == 0) {
        jclass notImplementedException = (*env)->FindClass(env, "com/pflager/glut$NotImplementedException");
        DPRINTF("notImplementedException == %p\n", notImplementedException);
        static char s[128];
        sprintf(s, "pname %d, not supported yet", pname);
        (*env)->ThrowNew(env, notImplementedException, s);
        return NULL;
    }

    float float_array[length];

    glGetFloatv(pname, float_array);

    jfloatArray jFloatArray = (*env)->NewFloatArray(env, length);  // allocate
    if (NULL == jFloatArray) {
    	return NULL;
    }

    (*env)->SetFloatArrayRegion(env, jFloatArray, 0 , length, float_array);  // copy

    return jFloatArray;
}
