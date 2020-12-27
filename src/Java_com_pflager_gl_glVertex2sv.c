#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex2sv(JNIEnv *env, jobject object, jshortArray vJShortArray) {
    DPRINTF("glVertex2sv(%p);\n", vJShortArray);

    if (vJShortArray == NULL) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 2 elements.");
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJShortArray);
    if (length != 2) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 2 elements.");
        return;
    }

    jshort *vJShortArrayElements = (*env)->GetShortArrayElements(env, vJShortArray, NULL);

    DPRINTF("glVertex2fv(new short[] {");
    for (unsigned i = 0; i < length; i++) {
    	if (i != 0) {
    		DPRINTF(", ");
    	}
    	DPRINTF("%.6d", vJShortArrayElements[i]);
    }
    DPRINTF("});\n");

    glVertex2sv(vJShortArrayElements);

    (*env)->ReleaseShortArrayElements(env, vJShortArray, vJShortArrayElements, 0); // release resources
}
