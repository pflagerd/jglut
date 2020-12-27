#include <assert.h>
#include <stdio.h>
#include <math.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT jdoubleArray JNICALL Java_com_pflager_glu_gluUnProject__DDD_3D_3D_3I(JNIEnv *env, jobject object, jdouble winXJDouble, jdouble winYJDouble, jdouble winZJDouble, jdoubleArray modelJDoubleArray, jdoubleArray projJDoubleArray, jintArray viewJIntArray) {
    DPRINTF("gluUnProject(%.17g%s, %.17g%s, %.17g%s, %p, %p, %p);\n", winXJDouble, winXJDouble == (int)winXJDouble ? ".0" : "", winYJDouble, winYJDouble == (int)winYJDouble ? ".0" : "", winZJDouble, winZJDouble == (int)winZJDouble ? ".0" : "", modelJDoubleArray, projJDoubleArray, viewJIntArray);

    jdoubleArray objXYZJDoubleArray = (*env)->NewDoubleArray(env, 3);  // allocate
    if (NULL == objXYZJDoubleArray) {
    	return NULL;
    }

	double objXYZ[3] = {-0.0, -0.0, -0.0};

	(*env)->SetDoubleArrayRegion(env, objXYZJDoubleArray, 0, 3, objXYZ);  // copy

    if (modelJDoubleArray == NULL) {
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
		(*env)->ThrowNew(env, illegalArgumentException, "model cannot be null.");
		return objXYZJDoubleArray;
	}

	jsize length = (*env)->GetArrayLength(env, modelJDoubleArray);
	if (length != 16) {
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
		(*env)->ThrowNew(env, illegalArgumentException, "model must contain exactly 16 elements.");
		return objXYZJDoubleArray;
	}

	jdouble *modelJDoubleArrayElements = (*env)->GetDoubleArrayElements(env, modelJDoubleArray, NULL);

	if (projJDoubleArray == NULL) {
		(*env)->ReleaseDoubleArrayElements(env, modelJDoubleArray, modelJDoubleArrayElements, 0); // release resources
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
		(*env)->ThrowNew(env, illegalArgumentException, "proj cannot be null.");
		return objXYZJDoubleArray;
	}

	length = (*env)->GetArrayLength(env, modelJDoubleArray);
	if (length != 16) {
		(*env)->ReleaseDoubleArrayElements(env, modelJDoubleArray, modelJDoubleArrayElements, 0); // release resources
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
		(*env)->ThrowNew(env, illegalArgumentException, "proj must contain exactly 16 elements.");
		return objXYZJDoubleArray;
	}

	jdouble *projJDoubleArrayElements = (*env)->GetDoubleArrayElements(env, projJDoubleArray, NULL);

	if (viewJIntArray == NULL) {
		(*env)->ReleaseDoubleArrayElements(env, modelJDoubleArray, modelJDoubleArrayElements, 0); // release resources
		(*env)->ReleaseDoubleArrayElements(env, projJDoubleArray, projJDoubleArrayElements, 0); // release resources
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
		(*env)->ThrowNew(env, illegalArgumentException, "view cannot be null.");
		return objXYZJDoubleArray;
	}

	length = (*env)->GetArrayLength(env, viewJIntArray);
	if (length != 4) {
		(*env)->ReleaseDoubleArrayElements(env, modelJDoubleArray, modelJDoubleArrayElements, 0); // release resources
		(*env)->ReleaseDoubleArrayElements(env, projJDoubleArray, projJDoubleArrayElements, 0); // release resources
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
		(*env)->ThrowNew(env, illegalArgumentException, "length must contain exactly 4 elements.");
		return objXYZJDoubleArray;
	}

	jint *viewJIntArrayElements = (*env)->GetIntArrayElements(env, viewJIntArray, NULL);

	GLint returnValue = gluUnProject(winXJDouble, winYJDouble, winZJDouble, modelJDoubleArrayElements, projJDoubleArrayElements, viewJIntArrayElements, objXYZ, objXYZ + 1, objXYZ + 2);
	if (returnValue == GL_TRUE) {
		(*env)->SetDoubleArrayRegion(env, objXYZJDoubleArray, 0, 3, objXYZ);  // copy
	}

	(*env)->ReleaseDoubleArrayElements(env, modelJDoubleArray, modelJDoubleArrayElements, 0); // release resources
	(*env)->ReleaseDoubleArrayElements(env, projJDoubleArray, projJDoubleArrayElements, 0); // release resources
	(*env)->ReleaseIntArrayElements(env, viewJIntArray, viewJIntArrayElements, 0); // release resources

	return objXYZJDoubleArray;
}
