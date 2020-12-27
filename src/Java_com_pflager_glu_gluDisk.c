#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT void JNICALL Java_com_pflager_glu_gluDisk(JNIEnv *env, jobject object, jobject quadJObject, jdouble innerJDouble, jdouble outerJDouble, jint slicesJInt, jint loopsJInt) {
    DPRINTF("gluDisk(%p, %.17g%s, %.17g%s, %d, %d);\n", quadJObject, innerJDouble, innerJDouble == (int)innerJDouble ? ".0" : "", outerJDouble, outerJDouble == (int)outerJDouble ? ".0" : "", slicesJInt, loopsJInt);

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

    gluDisk((GLUquadric*)gluquadric, innerJDouble, outerJDouble, slicesJInt, loopsJInt);
}
