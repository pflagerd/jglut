#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT void JNICALL Java_com_pflager_glu_gluBeginCurve(JNIEnv *env, jobject object, jobject nurbJObject) {
    DPRINTF("gluBeginCurve(%p);\n", nurbJObject);

    // Get a reference to this object's class
    jclass nurbJObjectClass = (*env)->GetObjectClass(env, nurbJObject);
    DPRINTF("nurbJObjectClass == %p\n", nurbJObjectClass); 
    if (NULL == nurbJObjectClass)
    	return;

    // int
    // Get the Field ID of the instance variables "number"
    jfieldID fidNumber = (*env)->GetFieldID(env, nurbJObjectClass, "address", "J");
    DPRINTF("fidNumber == %p\n", fidNumber); 
    if (NULL == fidNumber)
    	return;

    // Get the int given the Field ID
    jlong glunurbs = (*env)->GetLongField(env, nurbJObject, fidNumber);
    DPRINTF("glunurbs == %p\n", (GLUnurbs*)glunurbs);

    gluBeginCurve((GLUnurbs*)glunurbs);
}
