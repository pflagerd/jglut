#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT void JNICALL Java_com_pflager_glu_gluCylinder(JNIEnv *env, jobject object, jobject quadJObject, jdouble baseJDouble, jdouble topJDouble, jdouble heightJDouble, jint slicesJInt, jint stacksJInt) {
    DPRINTF("gluCylinder(%p, %.17g%s, %.17g%s, %.17g%s, %d, %d);\n", quadJObject, baseJDouble, baseJDouble == (int)baseJDouble ? ".0" : "", topJDouble, topJDouble == (int)topJDouble ? ".0" : "", heightJDouble, heightJDouble == (int)heightJDouble ? ".0" : "", slicesJInt, stacksJInt);

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

    gluCylinder((GLUquadric*)gluquadric, baseJDouble, topJDouble, heightJDouble, slicesJInt, stacksJInt);
}
