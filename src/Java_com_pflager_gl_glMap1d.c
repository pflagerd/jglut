#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glMap1d(JNIEnv *env, jobject object, jint target, jdouble u1, jdouble u2, jint stride, jint order, jobjectArray points) {
    if (points == NULL) {
        DPRINTF("glMap1d(0x%08x, %.17g%s, %.17g%s, %d, %d, null);\n", target, u1, u1 == (int)u1 ? ".0" : "", u2, u2 == (int)u2 ? ".0" : "", stride, order);
    	return;
    }

    jsize pointsLength = (*env)->GetArrayLength(env, points);
    if (pointsLength == 0) {
        DPRINTF("glMap1d(0x%08x, %.17g%s, %.17g%s, %d, %d, final new double [0][]);\n", target, u1, u1 == (int)u1 ? ".0" : "", u2, u2 == (int)u2 ? ".0" : "", stride, order);
    	return;
    }

    // DPRINTF("pointsLength == %d\n", pointsLength);

    GLdouble controlPoints[order][stride];

    DPRINTF("glMap1d(0x%08x, %.17g%s, %.17g%s, %d, %d, final new double[][] {\n", target, u1, u1 == (int)u1 ? ".0" : "", u2, u2 == (int)u2 ? ".0" : "", stride, order);
    for (unsigned i = 0; i < pointsLength; i++) {
    	if (i != 0) {
    		DPRINTF(",\n");
    	}

    	jdoubleArray jobjectArrayElement = (*env)->GetObjectArrayElement(env, points, i);

        jsize controlPointLength = (*env)->GetArrayLength(env, jobjectArrayElement);
        assert(controlPointLength == 3);
        // DPRINTF("controlPointLength == %d\n", controlPointLength);

    	jdouble *jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, jobjectArrayElement, NULL);

    	DPRINTF("  new double[] {");
    	for (unsigned j = 0; j < controlPointLength; j++) {
    		if (j != 0) {
    	    	DPRINTF(", ");
    		}
    		DPRINTF("%.17g%s", jdoubleArrayElements[j], jdoubleArrayElements[j] == (int)jdoubleArrayElements[j] ? ".0" : "");
    	}
    	DPRINTF("}");

    	memcpy(controlPoints[i], jdoubleArrayElements, 3 * sizeof(double));

   	    (*env)->ReleaseDoubleArrayElements(env, jobjectArrayElement, jdoubleArrayElements, 0); // release resources
    }

    DPRINTF("});\n");

    glMap1d(target, u1, u2, stride, order, (const GLdouble*)controlPoints);
}
