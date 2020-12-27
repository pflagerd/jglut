#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT void JNICALL Java_com_pflager_glu_gluNurbsSurface(JNIEnv *env, jobject object, jobject nurbJObject, jint sKnotCountJInt, jdoubleArray sKnotsJDoubleArray, jint tKnotCountJInt, jdoubleArray tKnotsJDoubleArray, jint sStrideJInt, jint tStrideJInt, jdoubleArray controlJDoubleArray, jint sOrderJInt, jint tOrderJInt, jint typeJInt) {
    DPRINTF("gluNurbsSurface(%p, %d, %p, %d, %p, %d, %d, %p, %d, %d, %d);\n", nurbJObject, sKnotCountJInt, sKnotsJDoubleArray, tKnotCountJInt, tKnotsJDoubleArray, sStrideJInt, tStrideJInt, controlJDoubleArray, sOrderJInt, tOrderJInt, typeJInt);

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

	if (sKnotsJDoubleArray == NULL) {
        char s[256];
        sprintf(s, "Pass a non-null sKnots array");
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    jsize length = (*env)->GetArrayLength(env, sKnotsJDoubleArray);

    jdouble* sKnotsJDoubleArrayElements = (*env)->GetDoubleArrayElements(env, sKnotsJDoubleArray, NULL);

    GLfloat sKnots[length];
    for (int i = 0; i < length; i++) {
    	sKnots[i] = (float)sKnotsJDoubleArrayElements[i];
    }

	if (tKnotsJDoubleArray == NULL) {
        char s[256];
        sprintf(s, "Pass a non-null sKnots array");
        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, illegalArgumentException, s);
    	return;
    }

    length = (*env)->GetArrayLength(env, tKnotsJDoubleArray);

    jdouble* tKnotsJDoubleArrayElements = (*env)->GetDoubleArrayElements(env, tKnotsJDoubleArray, NULL);

    GLfloat tKnots[length];
    for (int i = 0; i < length; i++) {
    	tKnots[i] = (float)tKnotsJDoubleArrayElements[i];
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
    	control[i] = (float)controlJDoubleArrayElements[i];
    }

    gluNurbsSurface((GLUnurbs*)glunurbs, sKnotCountJInt, sKnots, tKnotCountJInt, tKnots, sStrideJInt, tStrideJInt, control, sOrderJInt, tOrderJInt, typeJInt);
}
