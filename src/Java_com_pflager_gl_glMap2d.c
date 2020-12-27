#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glMap2d(JNIEnv *env, jobject object, jint target, jdouble u1, jdouble u2, jint ustride, jint uorder, jdouble v1, jdouble v2, jint vstride, jint vorder, jobjectArray points) {
    if (points == NULL) {
    	DPRINTF("glMap2d(0x%08x, %.17g%s, %.17g%s, %d, %d, %.17g%s, %.17g%s, %d, %d, null);\n", target, u1, u1 == (int)u1 ? ".0" : "", u2, u2 == (int)u2 ? ".0" : "", ustride, uorder, v1, v1 == (int)v1 ? ".0" : "", v2, v2 == (int)v2 ? ".0" : "", vstride, vorder);
    	return;
    }

    jsize controlPointsVOrder = (*env)->GetArrayLength(env, points);
    //DPRINTF("controlPointsVOrder == %d\n", controlPointsVOrder);
    if (controlPointsVOrder == 0) {
    	DPRINTF("glMap2d(0x%08x, %.17g%s, %.17g%s, %d, %d, %.17g%s, %.17g%s, %d, %d, final double[0][][]);\n", target, u1, u1 == (int)u1 ? ".0" : "", u2, u2 == (int)u2 ? ".0" : "", ustride, uorder, v1, v1 == (int)v1 ? ".0" : "", v2, v2 == (int)v2 ? ".0" : "", vstride, vorder);
    	return;
    }

    GLdouble controlPoints[vorder][uorder][ustride];

	DPRINTF("glMap2d(0x%08x, %.17g%s, %.17g%s, %d, %d, %.17g%s, %.17g%s, %d, %d, final double[][][] {\n", target, u1, u1 == (int)u1 ? ".0" : "", u2, u2 == (int)u2 ? ".0" : "", ustride, uorder, v1, v1 == (int)v1 ? ".0" : "", v2, v2 == (int)v2 ? ".0" : "", vstride, vorder);
    for (unsigned i = 0; i < controlPointsVOrder; i++) {
    	if (i != 0) {
    		DPRINTF(",\n");
    	}

    	jobjectArray controlPointsVObjectArrayElement = (*env)->GetObjectArrayElement(env, points, i);

        jsize controlPointsUOrder = (*env)->GetArrayLength(env, controlPointsVObjectArrayElement);
        //DPRINTF("controlPointsUOrder == %d\n", controlPointsUOrder);
        //assert(vControlPointLength == 4);

        for (unsigned j = 0; j < controlPointsUOrder; j++) {
        	jdoubleArray controlPointsUObjectArrayElement = (*env)->GetObjectArrayElement(env, controlPointsVObjectArrayElement, j);

        	jsize controlPointsUStride = (*env)->GetArrayLength(env, controlPointsUObjectArrayElement);

			jdouble *jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, controlPointsUObjectArrayElement, NULL);

			DPRINTF("  new double[] {");
			for (unsigned j = 0; j < controlPointsUStride; j++) {
				if (j != 0) {
					DPRINTF(", ");
				}
				DPRINTF("%.17g%s", jdoubleArrayElements[j], jdoubleArrayElements[j] == (int)jdoubleArrayElements[j] ? ".0" : "");
			}
			DPRINTF("}");

			memcpy(controlPoints[i][j], jdoubleArrayElements, controlPointsUStride * sizeof(double));

			(*env)->ReleaseDoubleArrayElements(env, controlPointsUObjectArrayElement, jdoubleArrayElements, 0); // release resources
        }
	}

    DPRINTF("});\n");

    glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, (const GLdouble *)controlPoints);
}
