#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex2fv(JNIEnv *env, jobject object, jfloatArray vJFloatArray) {
    DPRINTF("glVertex2fv(%p);\n", vJFloatArray);

    if (vJFloatArray == NULL) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 2 elements.");
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vJFloatArray);
    if (length != 2) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 2 elements.");
        return;
    }

    jfloat *vJFloatArrayElements = (*env)->GetFloatArrayElements(env, vJFloatArray, NULL);

    DPRINTF("glVertex2fv(new float[] {");
    for (unsigned i = 0; i < length; i++) {
    	if (i != 0) {
    		DPRINTF(", ");
    	}
    	DPRINTF("%.8g%s", vJFloatArrayElements[i], vJFloatArrayElements[i] == (int)vJFloatArrayElements[i] ? ".0" : "");
    }
    DPRINTF("});\n");

    glVertex2fv(vJFloatArrayElements);

    (*env)->ReleaseFloatArrayElements(env, vJFloatArray, vJFloatArrayElements, 0); // release resources
}
