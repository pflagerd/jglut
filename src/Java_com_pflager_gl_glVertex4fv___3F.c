#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex4fv___3F(JNIEnv *env, jobject object, jfloatArray vJFloatArray) {
    DPRINTF("glVertex4fv(%p);\n", vJFloatArray);

    jfloat *vJFloatCArray = (*env)->GetFloatArrayElements(env, vJFloatArray, NULL);
    if (NULL == vJFloatCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJFloatArray);
    if (3 != length) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        static char s[256];
        sprintf(s, "You must pass exactly %d elements.", 4);
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    glVertex4fv((const GLfloat*)vJFloatCArray);

    (*env)->ReleaseFloatArrayElements(env, vJFloatArray, vJFloatCArray, 0); // release resources
}
