#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glu.h"

#ifdef WIN32
#define _GLUfuncptr void (CALLBACK *)()
#endif

extern void throwIllegalArgumentException(JNIEnv *env, const char* fmt, ...);

static JavaVM* jvm = 0;

static jobject nurbsErrorGlobalRef; // TODO: DPP: 190105T120200: It's got a memory leak when the jvm shuts down because nurbsErrorGlobalRef is never de-allocated.

static void delegate(int type) {
	DPRINTF("ErrorFunc delegate(%d) called.\n", type);

	JNIEnv* env;
	(*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
//	DPRINTF("env == %p\n", env);

//	DPRINTF("nurbsErrorGlobalRef == %p\n", nurbsErrorGlobalRef);
	jclass errorFuncJClass = (*env)->GetObjectClass(env, nurbsErrorGlobalRef); // get interface from nurbsErrorJObject

//	DPRINTF("errorFuncJClass == %p\n", errorFuncJClass);
	jmethodID beginJMethodID = (*env)->GetMethodID(env, errorFuncJClass, "error", "(I)V");

//	DPRINTF("beginJMethodID == %p\n", beginJMethodID);
	(*env)->CallVoidMethod(env, nurbsErrorGlobalRef, beginJMethodID);

	(*jvm)->DetachCurrentThread(jvm);
}

JNIEXPORT void JNICALL Java_com_pflager_glu_gluNurbsCallback(JNIEnv *env, jobject object, jobject nurbJObject, jint whichJInt, jobject nurbsErrorJObject) {
    DPRINTF("gluNurbsCallback(%p, %d, %p);\n", nurbJObject, whichJInt, nurbsErrorJObject);

	if (nurbJObject == NULL) {
		throwIllegalArgumentException(env, "argument nurb cannot be null.");
		return;
	}

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
	GLUnurbs* glunurbs = (GLUnurbs*) (*env)->GetLongField(env, nurbJObject, fidNumber);
	DPRINTF("glunurbs == %p\n", glunurbs);

	if (nurbsErrorJObject == NULL) {
		if (nurbsErrorGlobalRef) {
			(*env)->DeleteGlobalRef(env, nurbsErrorGlobalRef);
			nurbsErrorGlobalRef = 0;
		}

		gluNurbsCallback((GLUnurbs*) glunurbs, whichJInt, NULL);
		return;
	}

	//	DPRINTF("object == %p\n", object);
	//	DPRINTF("nurbsErrorJObject == %p\n", nurbsErrorJObject);
	jclass errorFuncJClass = (*env)->GetObjectClass(env, nurbsErrorJObject); // get interface from nurbsErrorJObject
	//	DPRINTF("errorFuncJClass == %p\n", errorFuncJClass);

	(*env)->GetJavaVM(env, &jvm); //store jvm reference for later

	jobject previousNurbsErrorGlobalRef = nurbsErrorGlobalRef;

	nurbsErrorGlobalRef = (*env)->NewGlobalRef(env, nurbsErrorJObject); // Prevent the nurbsErrorJObject object from being garbage collected.
	//	DPRINTF("nurbsErrorGlobalRef == %p\n", nurbsErrorGlobalRef);

	if (previousNurbsErrorGlobalRef) {
		(*env)->DeleteGlobalRef(env, previousNurbsErrorGlobalRef);
	}

	// get begin() method from interface to make sure nurbsErrorJObject has one.
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

	gluNurbsCallback((GLUnurbs*) glunurbs, whichJInt, (_GLUfuncptr) delegate);
}
