#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT void JNICALL Java_com_pflager_glu_gluTessProperty(JNIEnv *env, jobject object, jobject tessJObject, jint whichJInt, jdouble dataJDouble) {
    DPRINTF("gluTessProperty(%p, %d, %.17g%s);\n", tessJObject, whichJInt, dataJDouble, dataJDouble == (int)dataJDouble ? ".0" : "");

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

    gluTessProperty((GLUtesselator*) glutesselator, whichJInt, dataJDouble);
}
