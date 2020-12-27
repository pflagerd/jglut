#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

#include "arrayOfDoublesToString.h"

JNIEXPORT void JNICALL Java_com_pflager_glu_gluTessVertex(JNIEnv *env, jobject object, jobject tessJObject, jdoubleArray locationJDoubleArray, jobject dataJObject) {
    DPRINTF("gluTessVertex(%p, %p, %p);\n", tessJObject, locationJDoubleArray, dataJObject);

	// Get a reference to this object's class
	jclass tessJObjectClass = (*env)->GetObjectClass(env, tessJObject);
	DPRINTF("tessJObjectClass == %p\n", tessJObjectClass);
	if (NULL == tessJObjectClass)
		return;

	// int
	// Get the Field ID of the instance variables "number"
	jfieldID fidNumber = (*env)->GetFieldID(env, tessJObjectClass, "address", "J");
	DPRINTF("fidNumber == %p\n", fidNumber);
	if (NULL == fidNumber)
		return;

	// Get the int given the Field ID
	jlong glutesselator = (*env)->GetLongField(env, tessJObject, fidNumber);
	DPRINTF("glutesselator == %p\n", (GLUtesselator*) glutesselator);

    jdouble* jdoubleArrayElements = (*env)->GetDoubleArrayElements(env, locationJDoubleArray, NULL);
	DPRINTF("jdoubleArrayElements == %p: %s\n", jdoubleArrayElements, arrayOfDoublesToString(jdoubleArrayElements, (*env)->GetArrayLength(env, locationJDoubleArray)));

    jobject dataJObjectGlobalReference = (*env)->NewGlobalRef(env, dataJObject);
	DPRINTF("dataJObjectGlobalReference == %p\n", (jobject*) dataJObjectGlobalReference);

    gluTessVertex((GLUtesselator*) glutesselator, jdoubleArrayElements, dataJObjectGlobalReference);

    (*env)->ReleaseDoubleArrayElements(env, locationJDoubleArray, jdoubleArrayElements, 0); // release resources

}
