#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT jint JNICALL Java_com_pflager_glu_gluUnProject__DDD_3D_3D_3I_3D(JNIEnv *env, jobject object, jdouble winXJDouble, jdouble winYJDouble, jdouble winZJDouble, jdoubleArray modelJDoubleArray, jdoubleArray projJDoubleArray, jintArray viewJIntArray, jdoubleArray objXYZJDoubleArray) {
	DPRINTF("gluUnProject(%.17g%s, %.17g%s, %.17g%s, %p, %p, %p, %p);\n", winXJDouble, winXJDouble == (int )winXJDouble ? ".0" : "", winYJDouble, winYJDouble == (int )winYJDouble ? ".0" : "", winZJDouble, winZJDouble == (int )winZJDouble ? ".0" : "", modelJDoubleArray, projJDoubleArray, viewJIntArray, objXYZJDoubleArray);
	if (modelJDoubleArray == NULL) {
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
		(*env)->ThrowNew(env, illegalArgumentException, "model cannot be null.");
		return GL_FALSE;
	}

	jsize length = (*env)->GetArrayLength(env, modelJDoubleArray);
	if (length != 16) {
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
		(*env)->ThrowNew(env, illegalArgumentException, "model must contain exactly 16 elements.");
		return GL_FALSE;
	}

	jdouble *modelJDoubleArrayElements = (*env)->GetDoubleArrayElements(env, modelJDoubleArray, NULL);

	if (projJDoubleArray == NULL) {
		(*env)->ReleaseDoubleArrayElements(env, modelJDoubleArray, modelJDoubleArrayElements, 0); // release resources
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
		(*env)->ThrowNew(env, illegalArgumentException, "proj cannot be null.");
		return GL_FALSE;
	}

	length = (*env)->GetArrayLength(env, modelJDoubleArray);
	if (length != 16) {
		(*env)->ReleaseDoubleArrayElements(env, modelJDoubleArray, modelJDoubleArrayElements, 0); // release resources
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
		(*env)->ThrowNew(env, illegalArgumentException, "proj must contain exactly 16 elements.");
		return GL_FALSE;
	}

	jdouble *projJDoubleArrayElements = (*env)->GetDoubleArrayElements(env, projJDoubleArray, NULL);

	if (viewJIntArray == NULL) {
		(*env)->ReleaseDoubleArrayElements(env, modelJDoubleArray, modelJDoubleArrayElements, 0); // release resources
		(*env)->ReleaseDoubleArrayElements(env, projJDoubleArray, projJDoubleArrayElements, 0); // release resources
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
		(*env)->ThrowNew(env, illegalArgumentException, "view cannot be null.");
		return GL_FALSE;
	}

	length = (*env)->GetArrayLength(env, viewJIntArray);
	if (length != 4) {
		(*env)->ReleaseDoubleArrayElements(env, modelJDoubleArray, modelJDoubleArrayElements, 0); // release resources
		(*env)->ReleaseDoubleArrayElements(env, projJDoubleArray, projJDoubleArrayElements, 0); // release resources
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
		(*env)->ThrowNew(env, illegalArgumentException, "length must contain exactly 4 elements.");
		return GL_FALSE;
	}

	jint *viewJIntArrayElements = (*env)->GetIntArrayElements(env, viewJIntArray, NULL);

	double objXYZ[3];

	GLint returnValue = gluUnProject(winXJDouble, winYJDouble, winZJDouble, modelJDoubleArrayElements, projJDoubleArrayElements, viewJIntArrayElements, objXYZ, objXYZ + 1, objXYZ + 2);
	if (returnValue == GL_TRUE) {
		length = (*env)->GetArrayLength(env, objXYZJDoubleArray);
		if (length != 3) {
			(*env)->ReleaseDoubleArrayElements(env, modelJDoubleArray, modelJDoubleArrayElements, 0); // release resources
			(*env)->ReleaseDoubleArrayElements(env, projJDoubleArray, projJDoubleArrayElements, 0); // release resources
			(*env)->ReleaseIntArrayElements(env, viewJIntArray, viewJIntArrayElements, 0); // release resources
			jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
			DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
			static char s[256];
			sprintf(s, "Pass an array with exactly %d elements.", 3);
			(*env)->ThrowNew(env, illegalArgumentException, s);
			return GL_FALSE;
		}

		(*env)->SetDoubleArrayRegion(env, objXYZJDoubleArray, 0, length, objXYZ);  // copy
	}

	(*env)->ReleaseDoubleArrayElements(env, modelJDoubleArray, modelJDoubleArrayElements, 0); // release resources
	(*env)->ReleaseDoubleArrayElements(env, projJDoubleArray, projJDoubleArrayElements, 0); // release resources
	(*env)->ReleaseIntArrayElements(env, viewJIntArray, viewJIntArrayElements, 0); // release resources

	return returnValue;
}
