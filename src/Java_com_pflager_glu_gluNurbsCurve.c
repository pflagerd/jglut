#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT void JNICALL Java_com_pflager_glu_gluNurbsCurve(JNIEnv *env, jobject object, jobject nurbJObject, jint knotCountJInt, jdoubleArray knotsJDoubleArray, jint strideJInt, jdoubleArray controlJDoubleArray, jint orderJInt, jint typeJInt) {
	DPRINTF("gluNurbsCurve(%p, %d, %p, %d, %p, %d, %d);\n", nurbJObject, knotCountJInt, knotsJDoubleArray, strideJInt, controlJDoubleArray, orderJInt, typeJInt);

	// Get a reference to this object's class
	jclass nurbJObjectClass = (*env)->GetObjectClass(env, nurbJObject);
	DPRINTF("nurbJObjectClass == %p\n", nurbJObjectClass);
	fflush(stdout);
	if (NULL == nurbJObjectClass)
		return;

	// int
	// Get the Field ID of the instance variables "number"
	jfieldID fidNumber = (*env)->GetFieldID(env, nurbJObjectClass, "address", "J");
	DPRINTF("fidNumber == %p\n", fidNumber);
	fflush(stdout);
	if (NULL == fidNumber)
		return;

	// Get the int given the Field ID
	jlong glunurbs = (*env)->GetLongField(env, nurbJObject, fidNumber);
	DPRINTF("glunurbs == %p\n", (GLUnurbs* )glunurbs);

	if (knotsJDoubleArray == NULL) {
		char s[256];
		sprintf(s, "Pass a non-null knots array");
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		(*env)->ThrowNew(env, illegalArgumentException, s);
		return;
	}

	jsize length = (*env)->GetArrayLength(env, knotsJDoubleArray);

	jdouble* knotsJDoubleArrayElements = (*env)->GetDoubleArrayElements(env, knotsJDoubleArray, NULL);

	GLfloat knots[length];
	for (int i = 0; i < length; i++) {
		knots[i] = (float) knotsJDoubleArrayElements[i];
	}

	length = (*env)->GetArrayLength(env, controlJDoubleArray);

	jdouble* controlJDoubleArrayElements = (*env)->GetDoubleArrayElements(env, controlJDoubleArray, NULL);

	if (controlJDoubleArrayElements == NULL) {
		char s[256];
		sprintf(s, "Pass a non-null control array");
		jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
		(*env)->ThrowNew(env, illegalArgumentException, s);
		return;
	}

	GLfloat control[length];
	for (int i = 0; i < length; i++) {
		control[i] = (float) controlJDoubleArrayElements[i];
	}

	gluNurbsCurve((GLUnurbs*)glunurbs, knotCountJInt, knots, strideJInt, control, orderJInt, typeJInt);
}
