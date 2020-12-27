#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex3iv(JNIEnv *env, jobject object, jintArray vJIntArray) {
    DPRINTF("glVertex3iv(%p);\n", vJIntArray);

    jint *vJIntCArray = (*env)->GetIntArrayElements(env, vJIntArray, NULL);
    if (NULL == vJIntCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJIntArray);
    if (3 != length) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        static char s[256];
        sprintf(s, "You must pass exactly %d elements.", 3);
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    glVertex3iv((const GLint*)vJIntCArray);

    (*env)->ReleaseIntArrayElements(env, vJIntArray, vJIntCArray, 0); // release resources
}
