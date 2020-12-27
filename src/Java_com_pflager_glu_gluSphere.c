#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT void JNICALL Java_com_pflager_glu_gluSphere(JNIEnv *env, jobject object, jobject quadJObject, jdouble radiusJDouble, jint slicesJInt, jint stacksJInt) {
    DPRINTF("gluSphere(%p, %.17g%s, %d, %d);\n", quadJObject, radiusJDouble, radiusJDouble == (int)radiusJDouble ? ".0" : "", slicesJInt, stacksJInt);

    // Get a reference to this object's class
    jclass quadJObjectClass = (*env)->GetObjectClass(env, quadJObject);
    DPRINTF("quadJObjectClass == %p\n", quadJObjectClass); 
    if (NULL == quadJObjectClass)
    	return;

    // int
    // Get the Field ID of the instance variables "number"
    jfieldID fidNumber = (*env)->GetFieldID(env, quadJObjectClass, "address", "J");
    DPRINTF("fidNumber == %p\n", fidNumber); 
    if (NULL == fidNumber)
    	return;

    // Get the int given the Field ID
    jlong gluquadric = (*env)->GetLongField(env, quadJObject, fidNumber);
    DPRINTF("gluquadric == %p\n", (GLUquadric*)gluquadric);

    gluSphere((GLUquadric*)gluquadric, radiusJDouble, slicesJInt, stacksJInt);
}
