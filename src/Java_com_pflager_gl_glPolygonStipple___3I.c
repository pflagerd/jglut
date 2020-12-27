#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glPolygonStipple___3I(JNIEnv *env, jobject object, jintArray maskJIntArray) {
    DPRINTF("glPolygonStipple(%p);\n", maskJIntArray);

	if (maskJIntArray == NULL) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 128);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, maskJIntArray);
    if (length != 128) {
        char s[256];
        sprintf(s, "Pass an array with exactly %d elements.", 128);
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
        return;
    }

    jint* jintArrayElements = (*env)->GetIntArrayElements(env, maskJIntArray, NULL);

    unsigned char byteMask[length];

    for (unsigned i = 0; i < length; i++) {
    	byteMask[i] = (unsigned char)jintArrayElements[i];
    }

    glPolygonStipple((const GLubyte*)byteMask);

	(*env)->ReleaseIntArrayElements(env, maskJIntArray, jintArrayElements, 0); // release resources
}
