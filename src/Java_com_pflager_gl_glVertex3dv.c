#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glVertex3dv(JNIEnv *env, jobject object, jdoubleArray vertex) {
    if (vertex == NULL) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 3 elements.");
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, vertex);
    if (length != 3) {
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, "Pass an array with exactly 3 elements.");
        return;
    }

    jdouble *jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, vertex, NULL);

    {
    	static char s[1024];
    	char* p = s;
		p += sprintf(p, "glVertex3dv(new double[] {");
		for (unsigned i = 0; i < length; i++) {
			if (i != 0) {
				p += sprintf(p, ", ");
			}
			p += sprintf(p, "%.17g%s", jdoubleArrayElements[i], jdoubleArrayElements[i] == (int)jdoubleArrayElements[i] ? ".0" : "");
		}
		p += sprintf(p, "});\n");
		DPRINTF(s);
    }

    glVertex3dv(jdoubleArrayElements);

    (*env)->ReleaseDoubleArrayElements(env, vertex, jdoubleArrayElements, 0); // release resources
}
