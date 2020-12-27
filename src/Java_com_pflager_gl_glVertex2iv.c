#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex2iv(JNIEnv *env, jobject object, jintArray vJIntArray) {
    DPRINTF("glVertex2iv(%p);\n", vJIntArray);

    if (vJIntArray == NULL) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 2 elements.");
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJIntArray);
    if (length != 2) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 2 elements.");
        return;
    }

    jint *vJIntArrayElements = (*env)->GetIntArrayElements(env, vJIntArray, NULL);

    DPRINTF("glVertex2iv(new int[] {");
    for (unsigned i = 0; i < length; i++) {
    	if (i != 0) {
    		DPRINTF(", ");
    	}
    	DPRINTF("%.10d", vJIntArrayElements[i]);
    }
    DPRINTF("});\n");

    glVertex2iv(vJIntArrayElements);

    (*env)->ReleaseIntArrayElements(env, vJIntArray, vJIntArrayElements, 0); // release resources
}
