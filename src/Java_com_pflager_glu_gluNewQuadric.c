#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

JNIEXPORT jobject JNICALL Java_com_pflager_glu_gluNewQuadric(JNIEnv *env, jobject object) {
    DPRINTF("gluNewQuadric();\n");

    GLUquadric* gluquadric = gluNewQuadric();

    jclass cls = (*env)->FindClass(env, "Lcom/pflager/glu$GLUquadric;"); // /GLUquadric
    DPRINTF("cls == %p\n", cls); 
    if (NULL == cls)
    	return NULL;

    jmethodID midInit = (*env)->GetMethodID(env, cls, "<init>", "()V");// Lcom/pflager/glu;void
    DPRINTF("midInit == %p\n", midInit); 
    if (NULL == midInit)
    	return NULL;

    // Call back constructor to allocate a new instance with the default constructor
    jobject newObj = (*env)->NewObject(env, cls, midInit);
    DPRINTF("newObj == %p\n", newObj); 
    if (NULL == newObj)
    	return NULL;

    jfieldID fidNumber = (*env)->GetFieldID(env, cls, "address", "J");
    DPRINTF("fidNumber == %p\n", fidNumber); 
    if (NULL == fidNumber)
    	return NULL;

    (*env)->SetLongField(env, newObj, fidNumber, (jlong)gluquadric);
    DPRINTF("SetLongField() set to %p\n", gluquadric); 

    return newObj;
}
