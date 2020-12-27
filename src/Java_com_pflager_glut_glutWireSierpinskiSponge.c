#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutWireSierpinskiSponge(JNIEnv *env, jobject object, jint num_levels, jdoubleArray offsetjDoubleArray, jdouble scale) {
    DPRINTF("glutWireSierpinskiSponge(%d, %p, %.17g%s);\n", num_levels, offsetjDoubleArray, scale, scale == (int)scale ? ".0" : "");

    jsize length = (*env)->GetArrayLength(env, offsetjDoubleArray);
    if (length != 3) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 3 elements.");
        return;
    }

    jdouble *jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, offsetjDoubleArray, NULL);

    glutWireSierpinskiSponge(num_levels, jdoubleArrayElements, scale);

    (*env)->ReleaseDoubleArrayElements(env, offsetjDoubleArray, jdoubleArrayElements, 0); // release resources
}
