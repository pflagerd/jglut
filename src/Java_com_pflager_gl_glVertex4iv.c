#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex4iv(JNIEnv *env, jobject object, jintArray vJIntArray) {
    DPRINTF("glVertex4iv(%p);\n", vJIntArray);

    jint *vJIntCArray = (*env)->GetIntArrayElements(env, vJIntArray, NULL);
    if (NULL == vJIntCArray) {
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJIntArray);
    if (3 != length) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        static char s[256];
        sprintf(s, "You must pass exactly %d elements.", 4);
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    glVertex4iv((const GLint*)vJIntCArray);

    (*env)->ReleaseIntArrayElements(env, vJIntArray, vJIntCArray, 0); // release resources}

}
