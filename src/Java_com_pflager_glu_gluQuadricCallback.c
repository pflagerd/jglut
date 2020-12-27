#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

#ifdef WIN32
#define _GLUfuncptr void (CALLBACK *)()
#endif

extern void throwIllegalArgumentException(JNIEnv *env, const char* fmt, ...);

static JavaVM* jvm = 0;

static jobject errorFuncGlobalRef; // TODO: DPP: 190105T120200: It's got a memory leak when the jvm shuts down because errorFuncGlobalRef is never de-allocated.

static void delegate(int type) {
	DPRINTF("ErrorFunc delegate(%d) called.\n", type);

	JNIEnv* env;
	(*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
//	DPRINTF("env == %p\n", env);

//	DPRINTF("errorFuncGlobalRef == %p\n", errorFuncGlobalRef);
	jclass errorFuncJClass = (*env)->GetObjectClass(env, errorFuncGlobalRef); // get interface from errorFuncJObject

//	DPRINTF("errorFuncJClass == %p\n", errorFuncJClass);
	jmethodID beginJMethodID = (*env)->GetMethodID(env, errorFuncJClass, "error", "(I)V");

//	DPRINTF("beginJMethodID == %p\n", beginJMethodID);
	(*env)->CallVoidMethod(env, errorFuncGlobalRef, beginJMethodID);

	(*jvm)->DetachCurrentThread(jvm);
}

JNIEXPORT void JNICALL Java_com_pflager_glu_gluQuadricCallback(JNIEnv *env, jobject object, jobject quadJObject, jint whichJInt, jobject errorFuncJObject) {
	DPRINTF("gluQuadricCallback(%p, %d, %p);\n", quadJObject, whichJInt, errorFuncJObject);
	if (quadJObject == NULL) {
		throwIllegalArgumentException(env, "argument quad cannot be null.");
		return;
	}

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
	GLUquadric* gluquadric = (GLUquadric*) (*env)->GetLongField(env, quadJObject, fidNumber);
	DPRINTF("gluquadric == %p\n", gluquadric);

	if (errorFuncJObject == NULL) {
		if (errorFuncGlobalRef) {
			(*env)->DeleteGlobalRef(env, errorFuncGlobalRef);
			errorFuncGlobalRef = 0;
		}

		gluQuadricCallback((GLUquadric*) gluquadric, whichJInt, NULL);
		return;
	}

	//	DPRINTF("object == %p\n", object);
	//	DPRINTF("errorFuncJObject == %p\n", errorFuncJObject);
	jclass errorFuncJClass = (*env)->GetObjectClass(env, errorFuncJObject); // get interface from errorFuncJObject
	//	DPRINTF("errorFuncJClass == %p\n", errorFuncJClass);

	(*env)->GetJavaVM(env, &jvm); //store jvm reference for later

	jobject previousErrorFuncGlobalRef = errorFuncGlobalRef;

	errorFuncGlobalRef = (*env)->NewGlobalRef(env, errorFuncJObject); // Prevent the errorFuncJObject object from being garbage collected.
	//	DPRINTF("errorFuncGlobalRef == %p\n", errorFuncGlobalRef);

	if (previousErrorFuncGlobalRef) {
		(*env)->DeleteGlobalRef(env, previousErrorFuncGlobalRef);
	}

	// get begin() method from interface to make sure errorFuncJObject has one.
	jmethodID beginJMethodID = (*env)->GetMethodID(env, errorFuncJClass, "error", "(I)V");
	//	DPRINTF("beginJMethodID == %p\n", beginJMethodID);
	if (NULL == beginJMethodID) {
		jmethodID getClassJMethodID = (*env)->GetMethodID(env, errorFuncJClass, "getClass", "()Ljava/lang/Class;"); // get jmethodID of getClass() method.
		jobject classJObject = (*env)->CallObjectMethod(env, errorFuncJClass, getClassJMethodID); // Call getClass() to retrieve a jobject to its class.

		jclass classJClass = (*env)->GetObjectClass(env, classJObject); // get the jclass of the classJObject

		jmethodID getNameJMethodID = (*env)->GetMethodID(env, classJClass, "getName", "()Ljava/lang/String;"); // get jmethodID of getName() method.
		jstring classNameJString = (*env)->CallObjectMethod(env, classJClass, getNameJMethodID); // call getName() on classJClass to retrieve the class' jstring name
		const char *className = (*env)->GetStringUTFChars(env, classNameJString, NULL); // retrieve a const char* to the UTF representation of the string.

		throwIllegalArgumentException(env, "Class %s has no public void begin(int) override.", className);
		return; // ThrowNew never returns anyway. This keeps the compiler happy.
	}

	gluQuadricCallback((GLUquadric*) gluquadric, whichJInt, (_GLUfuncptr) delegate);

}
