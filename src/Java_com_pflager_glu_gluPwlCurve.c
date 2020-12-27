#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT void JNICALL Java_com_pflager_glu_gluPwlCurve(JNIEnv *env, jobject object, jobject nurbJObject, jint countJInt, jdoubleArray dataJDoubleArray, jint strideJInt, jint typeJInt) {
    DPRINTF("gluPwlCurve(%p, %d, %p, %d, %d);\n", nurbJObject, countJInt, dataJDoubleArray, strideJInt, typeJInt);

    // Get a reference to this object's class
    jclass nurbJObjectClass = (*env)->GetObjectClass(env, nurbJObject);
    DPRINTF("nurbJObjectClass == %p\n", nurbJObjectClass); fflush(stdout);
    if (NULL == nurbJObjectClass)
    	return;

    // int
    // Get the Field ID of the instance variables "number"
    jfieldID fidNumber = (*env)->GetFieldID(env, nurbJObjectClass, "address", "J");
    DPRINTF("fidNumber == %p\n", fidNumber); fflush(stdout);
    if (NULL == fidNumber)
    	return;

    // Get the int given the Field ID
    jlong glunurbs = (*env)->GetLongField(env, nurbJObject, fidNumber);
    DPRINTF("glunurbs == %p\n", (GLUnurbs*)glunurbs);

	if (dataJDoubleArray == NULL) {
        char s[256];
        sprintf(s, "Pass a non-null data array");
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, dataJDoubleArray);

    jdouble* dataJDoubleArrayElements = (*env)->GetDoubleArrayElements(env, dataJDoubleArray, NULL);

    GLfloat data[length];
    for (int i = 0; i < length; i++) {
    	data[i] = (float)dataJDoubleArrayElements[i];
    }

    gluPwlCurve((GLUnurbs*)glunurbs, countJInt, data, strideJInt, typeJInt);

}
