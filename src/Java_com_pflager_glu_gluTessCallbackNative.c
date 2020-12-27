#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "jglut.h"

#include "com_pflager_glu.h"

#include "arrayOfDoublesToString.h"
#include "arrayOfFloatsToString.h"
#include "arrayOfPointersToString.h"

#ifdef WIN32
#define _GLUfuncptr void (CALLBACK *)()
#endif

void throwIllegalArgumentException(JNIEnv *env, const char* fmt, ...) {
	va_list (args);
	va_start(args, fmt);
	char s[vsnprintf(NULL, 0, fmt, args)];
	va_end(args);

	{
		va_list (args);
		va_start(args, fmt);
		vsprintf(s, fmt, args);
		va_end(args);
	}

	jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
	(*env)->ThrowNew(env, illegalArgumentException, s);
}

static JavaVM* jvm = 0;

static jobject beginFuncGlobalRef; // TODO: DPP: 190105T120200: It's got a memory leak when the jvm shuts down because beginFuncGlobalRef is never de-allocated.
static jobject combineFuncGlobalRef; // TODO: DPP: 190105T120200: It's got a memory leak when the jvm shuts down because combineFuncGlobalRef is never de-allocated.
static jobject endFuncGlobalRef; // TODO: DPP: 190105T120200: It's got a memory leak when the jvm shuts down because endFuncGlobalRef is never de-allocated.
static jobject errorFuncGlobalRef; // TODO: DPP: 190105T120200: It's got a memory leak when the jvm shuts down because errorFuncGlobalRef is never de-allocated.
static jobject vertexFuncGlobalRef; // TODO: DPP: 190105T120200: It's got a memory leak when the jvm shuts down because vertexFuncGlobalRef is never de-allocated.

static void beginFuncDelegate(int which) {
	DPRINTF("BeginFunc beginFuncDelegate(%d) called.\n", which);

	JNIEnv* env;
	(*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
//	DPRINTF("env == %p\n", env);

//	DPRINTF("beginFuncGlobalRef == %p\n", beginFuncGlobalRef);
	jclass callbackJClass = (*env)->GetObjectClass(env, beginFuncGlobalRef); // get interface from errorFuncJObject

//	DPRINTF("callbackJClass == %p\n", callbackJClass);
	jmethodID jMethodID = (*env)->GetMethodID(env, callbackJClass, "begin", "(I)V");

//	DPRINTF("beginJMethodID == %p\n", beginJMethodID);
	(*env)->CallVoidMethod(env, beginFuncGlobalRef, jMethodID, which);

	(*jvm)->DetachCurrentThread(jvm);
}

static void combineFuncDelegate(GLdouble coords[/* 3 */], void* vertex_data[/* 4 */], GLfloat weight[/* 4 */], void** outData) {
	DPRINTF("CombineFunc combineFuncDelegate(%p, %p, %p, %p) called.\n", coords, vertex_data, weight, outData);

	DPRINTF("coords[] == %s\n", arrayOfDoublesToString(coords, 3));

	DPRINTF("vertex_data*[] == %s\n", arrayOfPointersToString(vertex_data, 4));

	DPRINTF("weight[] == %s\n", arrayOfFloatsToString(weight, 4));

	JNIEnv* env;
	(*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
//	DPRINTF("env == %p\n", env);

	// TODO: DPP: 200204220919: I think I may need to take the coords, vertex_data, weight and maybe outData and create
	// specific java objects for them.  Then Maybe I can pass these object to combine.
	jdoubleArray jCoords = (*env)->NewDoubleArray(env, 3);
	(*env)->SetDoubleArrayRegion(env, jCoords, 0, 3, coords);

	jclass jVertexDataArrayElementClass = (*env)->FindClass(env, "[D");
	DPRINTF("jVertexDataArrayElementClass == %p\n", jVertexDataArrayElementClass);

	jobject jVertexDataArray = (*env)->NewObjectArray(env, 4, jVertexDataArrayElementClass, 0);
	DPRINTF("jVertexDataArray == %p\n", jVertexDataArray);

	for (int i = 0; i < 4 && vertex_data[i]; i++) {
		DPRINTF("vertex_data[%d] == %p\n", i, vertex_data[i]);

		jsize vertex_data_length = (*env)->GetArrayLength(env, (jobject)vertex_data[i]);
		DPRINTF("vertex_data_length == %zu\n", vertex_data_length);

		jdouble* jVertexDataArrayElements = (*env)->GetDoubleArrayElements(env, (jdoubleArray)vertex_data[i], 0);
		DPRINTF("jVertexDataArrayElements[] == %s\n", arrayOfDoublesToString(jVertexDataArrayElements, vertex_data_length));

		(*env)->SetObjectArrayElement(env, jVertexDataArray, i, vertex_data[i]);
	}

	jfloatArray jWeight = (*env)->NewFloatArray(env, 4);
	(*env)->SetFloatArrayRegion(env, jWeight, 0, 4, weight);

	jobject joutDataArray = (*env)->NewDoubleArray(env, 6);
	DPRINTF("joutDataArray == %p\n", joutDataArray);



	DPRINTF("combineFuncGlobalRef == %p\n", combineFuncGlobalRef);

	jclass callbackJClass = (*env)->GetObjectClass(env, combineFuncGlobalRef); // get interface from errorFuncJObject
	DPRINTF("callbackJClass == %p\n", callbackJClass);

	jmethodID jCombineMethodID = (*env)->GetMethodID(env, callbackJClass, "combine", "([D[Ljava/lang/Object;[DLjava/lang/Object;)V");
	DPRINTF("jCombineMethodID == %p\n", jCombineMethodID);

	(*env)->CallVoidMethod(env, combineFuncGlobalRef, jCombineMethodID, jCoords, jVertexDataArray, jWeight, joutDataArray);
	DPRINTF("joutDataArray == %p\n", joutDataArray);

	// retrieve the data
	jdouble* joutDataArrayElements = (*env)->GetDoubleArrayElements(env, joutDataArray, 0);
	DPRINTF("joutDataArrayElements == %p\n", joutDataArrayElements);

	GLdouble* outDataResults = (GLdouble*)calloc(6, sizeof(GLdouble));
	memcpy(outDataResults, joutDataArrayElements, 6 * sizeof(GLdouble));

	*outData = outDataResults;

	(*env)->ReleaseDoubleArrayElements(env, joutDataArray, joutDataArrayElements, JNI_ABORT);

	jclass outDataJClass = (*env)->GetObjectClass(env, joutDataArray);
	DPRINTF("outDataJClass == %p\n", combineFuncGlobalRef);

	jmethodID jgetClassMethodID = (*env)->GetMethodID(env, outDataJClass, "getClass", "()Ljava/lang/Class;");
	DPRINTF("jgetClassMethodID == %p\n", jgetClassMethodID);

	jobject outDataClassJObject = (*env)->CallObjectMethod(env, joutDataArray, jgetClassMethodID);
	DPRINTF("outDataClassJObject == %p\n", outDataClassJObject);

	jclass outDataClassJClass = (*env)->GetObjectClass(env, outDataClassJObject); // get interface from errorFuncJObject
	DPRINTF("outDataClassJClass == %p\n", outDataClassJObject);

	jmethodID jgetNameMethodID = (*env)->GetMethodID(env, outDataClassJClass, "getName", "()Ljava/lang/String;");
	DPRINTF("jgetNameMethodID == %p\n", jgetNameMethodID);

	jstring stringJObject = (*env)->CallObjectMethod(env, outDataClassJObject, jgetNameMethodID);
	DPRINTF("stringJObject == %p\n", stringJObject);

	const char* className = (*env)->GetStringUTFChars(env, stringJObject, NULL);
	DPRINTF("className == \"%s\"\n", className);
	(*env)->ReleaseStringUTFChars(env, stringJObject, className);

//	jobject outDataGlobalRef = (*env)->NewGlobalRef(env, *outData); // Prevent the outData object from being garbage collected.
//	DPRINTF("outDataGlobalRef == %p\n", outDataGlobalRef);

	(*jvm)->DetachCurrentThread(jvm);
}

static void endFuncDelegate() {
	DPRINTF("EndFunc endFuncDelegate() called.\n");

	JNIEnv* env;
	(*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
	DPRINTF("env == %p\n", env);

	DPRINTF("endFuncGlobalRef == %p\n", endFuncGlobalRef);
	jclass callbackJClass = (*env)->GetObjectClass(env, endFuncGlobalRef); // get interface from endFuncJObject

	DPRINTF("callbackJClass == %p\n", callbackJClass);
	jmethodID jMethodID = (*env)->GetMethodID(env, callbackJClass, "end", "()V");

	DPRINTF("endJMethodID == %p\n", jMethodID);
	(*env)->CallVoidMethod(env, endFuncGlobalRef, jMethodID);

	(*jvm)->DetachCurrentThread(jvm);
}

static void errorFuncDelegate(int errno) {
	DPRINTF("ErrorFunc errorFuncDelegate(%d) called.\n", errno);

	JNIEnv* env;
	(*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
//	DPRINTF("env == %p\n", env);

//	DPRINTF("errorFuncGlobalRef == %p\n", errorFuncGlobalRef);
	jclass callbackJClass = (*env)->GetObjectClass(env, errorFuncGlobalRef); // get interface from errorFuncJObject

//	DPRINTF("callbackJClass == %p\n", callbackJClass);
	jmethodID jMethodID = (*env)->GetMethodID(env, callbackJClass, "error", "(I)V");

//	DPRINTF("errorJMethodID == %p\n", errorJMethodID);
	(*env)->CallVoidMethod(env, errorFuncGlobalRef, jMethodID, errno);

	(*jvm)->DetachCurrentThread(jvm);
}

static void vertexFuncDelegate(void* vertex_data) {
	DPRINTF("VertexFunc vertexFuncDelegate(%p) called.\n", vertex_data);

	JNIEnv* env;
	(*jvm)->AttachCurrentThread(jvm, (void**) &env, NULL);
	DPRINTF("  env == %p\n", env);

	DPRINTF("  vertexFuncGlobalRef == %p\n", vertexFuncGlobalRef);
	jclass callbackJClass = (*env)->GetObjectClass(env, vertexFuncGlobalRef); // get interface from vertexFuncJObjec
	DPRINTF("  callbackJClass == %p\n", callbackJClass);

	jmethodID jMethodID = (*env)->GetMethodID(env, callbackJClass, "vertex", "(Ljava/lang/Object;)V");
	DPRINTF("  jMethodID == %p\n", jMethodID);

	DPRINTF("  About to CallVoidMethod(%p)\n", vertex_data);
	(*env)->CallVoidMethod(env, vertexFuncGlobalRef, jMethodID, vertex_data);
	DPRINTF("  Called CallVoidMethod(%p)\n", vertex_data);

	(*jvm)->DetachCurrentThread(jvm);
	DPRINTF("  Called DetachCurrentThread()\n");
}

static const char* getCallbackInterfaceName(int which) {
	static const char* ids[] = { "BeginFunc", "VertexFunc", "EndFunc", "ErrorFunc", "EdgeFlagFunc", "CombineFunc", "BeginDataFunc", "VertexDataFunc", "EndDataFunc", "ErrorDataFunc", "EdgeFlagDataFunc", "CombineDataFunc" };
	static char s[128];

	if (which < GLU_TESS_BEGIN || which > GLU_TESS_COMBINE_DATA) {
		sprintf(s, "<unknown interface %d>", which);
		return (const char*) s;
	}

	return ids[which - GLU_TESS_BEGIN];
}

const char* decodeWhich(int which) {
	static const char* ids[] = { "GLU_TESS_BEGIN", "GLU_TESS_VERTEX", "GLU_TESS_END", "GLU_TESS_ERROR", "GLU_TESS_EDGE_FLAG", "GLU_TESS_COMBINE", "GLU_TESS_BEGIN_DATA", "GLU_TESS_VERTEX_DATA", "GLU_TESS_END_DATA", "GLU_TESS_ERROR_DATA", "GLU_TESS_EDGE_FLAG_DATA", "GLU_TESS_COMBINE_DATA" };
	static char s[128];

	if (which < GLU_TESS_BEGIN || which > GLU_TESS_COMBINE_DATA) {
		sprintf(s, "<unknown 'which' %d>", which);
		return (const char*) s;
	}

	return ids[which - GLU_TESS_BEGIN];
}
;

JNIEXPORT void JNICALL Java_com_pflager_glu_gluTessCallbackNative(JNIEnv *env, jobject object, jobject tessJObject, jint whichJInt, jobject callbackJObject) {
	DPRINTF("gluTessCallback(%p, %s, %p);\n", tessJObject, decodeWhich(whichJInt), callbackJObject);

	DPRINTF("callbackJObject == %p\n", callbackJObject);

	if (tessJObject == NULL) {
		throwIllegalArgumentException(env, "argument tess cannot be null.");
		return;
	}

	// Get a reference to this object's class
	jclass tessJObjectClass = (*env)->GetObjectClass(env, tessJObject);
	DPRINTF("  tessJObjectClass == %p\n", tessJObjectClass);
	
	if (NULL == tessJObjectClass)
		return;

	// int
	// Get the Field ID of the instance variables "number"
	jfieldID fidNumber = (*env)->GetFieldID(env, tessJObjectClass, "address", "J");
	DPRINTF("  fidNumber == %p\n", fidNumber);
	
	if (NULL == fidNumber)
		return;

	// Get the int given the Field ID
	GLUtesselator* glutesselator = (GLUtesselator*) (*env)->GetLongField(env, tessJObject, fidNumber);
	DPRINTF("  glutesselator == %p\n", glutesselator);

	if (callbackJObject == NULL) {
		switch (whichJInt) {
			case GLU_TESS_BEGIN:
				(*env)->DeleteGlobalRef(env, beginFuncGlobalRef);
				beginFuncGlobalRef = 0;
				break;

			case GLU_TESS_COMBINE:
				(*env)->DeleteGlobalRef(env, combineFuncGlobalRef);
				combineFuncGlobalRef = 0;
				break;

			case GLU_TESS_END:
				(*env)->DeleteGlobalRef(env, endFuncGlobalRef);
				endFuncGlobalRef = 0;
				break;

			case GLU_TESS_ERROR:
				(*env)->DeleteGlobalRef(env, errorFuncGlobalRef);
				errorFuncGlobalRef = 0;
				break;

			case GLU_TESS_VERTEX:
				(*env)->DeleteGlobalRef(env, vertexFuncGlobalRef);
				vertexFuncGlobalRef = 0;
				break;

			default:
				DPRINTF("IllegalArgumentException: %s is not a valid argument value for the 'which' parameter.", decodeWhich(whichJInt))
				;
				throwIllegalArgumentException(env, "%s is not a valid argument value for the 'which' parameter.", decodeWhich(whichJInt));
				break;
		}

		gluTessCallback((GLUtesselator*) glutesselator, whichJInt, NULL);
		return;
	}

	//	DPRINTF("object == %p\n", object);
	//	DPRINTF("errorFuncJObject == %p\n", errorFuncJObject);
	jclass callbackJClass = (*env)->GetObjectClass(env, callbackJObject); // get interface from errorFuncJObject
	//	DPRINTF("callbackJClass == %p\n", callbackJClass);

	(*env)->GetJavaVM(env, &jvm); //store jvm reference for later

	switch (whichJInt) {
		case GLU_TESS_BEGIN: {
			jobject previousBeginFuncGlobalRef = beginFuncGlobalRef;

			beginFuncGlobalRef = (*env)->NewGlobalRef(env, callbackJObject); // Prevent the beginFuncJObject object from being garbage collected.
			DPRINTF("  beginFuncGlobalRef == %p\n", beginFuncGlobalRef);

			if (previousBeginFuncGlobalRef) {
				(*env)->DeleteGlobalRef(env, previousBeginFuncGlobalRef);
			}

			// get begin() method from interface to make sure beginFuncJObject has one.
			jmethodID jMethodID = (*env)->GetMethodID(env, callbackJClass, "begin", "(I)V");
			DPRINTF("  jMethodID == %p\n", jMethodID);
			if (NULL == jMethodID) {
				throwIllegalArgumentException(env, "Class %s has no public method void begin(int) to override.", getCallbackInterfaceName(whichJInt));
				return; // ThrowNew never returns anyway. This keeps the compiler happy.
			}

			gluTessCallback((GLUtesselator*) glutesselator, whichJInt, (_GLUfuncptr) beginFuncDelegate);
			return;
		}

		case GLU_TESS_COMBINE: {
			jobject previousCombineFuncGlobalRef = combineFuncGlobalRef;

			combineFuncGlobalRef = (*env)->NewGlobalRef(env, callbackJObject); // Prevent the beginFuncJObject object from being garbage collected.
			DPRINTF("  beginFuncGlobalRef == %p\n", combineFuncGlobalRef);

			if (previousCombineFuncGlobalRef) {
				(*env)->DeleteGlobalRef(env, previousCombineFuncGlobalRef);
			}

			// get combine() method from interface to make sure combineFuncJObject has one.
			jmethodID jMethodID = (*env)->GetMethodID(env, callbackJClass, "combine", "([D[Ljava/lang/Object;[DLjava/lang/Object;)V");
			DPRINTF("  jMethodID == %p\n", jMethodID);
			if (NULL == jMethodID) {
				throwIllegalArgumentException(env, "Class %s has no public method void combine(double[] coords, Object[] vertex_data, double[] eight, Object obj) to override.", getCallbackInterfaceName(whichJInt));
				return; // ThrowNew never returns anyway. This keeps the compiler happy.
			}

			gluTessCallback((GLUtesselator*) glutesselator, whichJInt, (_GLUfuncptr) combineFuncDelegate);
			return;
		}

		case GLU_TESS_END: {
			jobject previousEndFuncGlobalRef = endFuncGlobalRef;

			endFuncGlobalRef = (*env)->NewGlobalRef(env, callbackJObject); // Prevent the endFuncJObject object from being garbage collected.
			DPRINTF("  endFuncGlobalRef == %p\n", endFuncGlobalRef);

			if (previousEndFuncGlobalRef) {
				(*env)->DeleteGlobalRef(env, previousEndFuncGlobalRef);
			}

			// get end() method from interface to make sure endFuncJObject has one.
			jmethodID jMethodID = (*env)->GetMethodID(env, callbackJClass, "end", "()V");
			DPRINTF("  jMethodID == %p\n", jMethodID);
			if (NULL == jMethodID) {
				throwIllegalArgumentException(env, "Class %s has no public method void end() to override.", getCallbackInterfaceName(whichJInt));
				return; // ThrowNew never returns anyway. This keeps the compiler happy.
			}

			gluTessCallback((GLUtesselator*) glutesselator, whichJInt, (_GLUfuncptr) endFuncDelegate);
			return;
		}

		case GLU_TESS_ERROR: {
			jobject previousErrorFuncGlobalRef = errorFuncGlobalRef;

			errorFuncGlobalRef = (*env)->NewGlobalRef(env, callbackJObject); // Prevent the errorFuncJObject object from being garbage collected.
			DPRINTF("  errorFuncGlobalRef == %p\n", errorFuncGlobalRef);

			if (previousErrorFuncGlobalRef) {
				(*env)->DeleteGlobalRef(env, previousErrorFuncGlobalRef);
			}

			// get error() method from interface to make sure errorFuncJObject has one.
			jmethodID jMethodID = (*env)->GetMethodID(env, callbackJClass, "error", "(I)V");
			DPRINTF("  jMethodID == %p\n", jMethodID);
			if (NULL == jMethodID) {
				throwIllegalArgumentException(env, "Class %s has no public method void error(int) to override.", getCallbackInterfaceName(whichJInt));
				return; // ThrowNew never returns anyway. This keeps the compiler happy.
			}

			gluTessCallback((GLUtesselator*) glutesselator, whichJInt, (_GLUfuncptr) errorFuncDelegate);
			return;
		}

		case GLU_TESS_VERTEX: {
			jobject previousvertexFuncGlobalRef = vertexFuncGlobalRef;

			vertexFuncGlobalRef = (*env)->NewGlobalRef(env, callbackJObject); // Prevent the vertexFuncJObject object from being garbage collected.
			DPRINTF("vertexFuncGlobalRef == %p\n", vertexFuncGlobalRef);

			if (previousvertexFuncGlobalRef) {
				(*env)->DeleteGlobalRef(env, previousvertexFuncGlobalRef);
			}

			jmethodID jMethodID = (*env)->GetMethodID(env, callbackJClass, "vertex", "(Ljava/lang/Object;)V");
			DPRINTF("  jMethodID == %p\n", jMethodID);
			if (NULL == jMethodID) {
				throwIllegalArgumentException(env, "Class %s has no public method void vertex(Object) to override.", getCallbackInterfaceName(whichJInt));
				return; // ThrowNew never returns anyway. This keeps the compiler happy.
			}

			gluTessCallback((GLUtesselator*) glutesselator, whichJInt, (_GLUfuncptr) vertexFuncDelegate);
			return;
		}

		default:
			DPRINTF("IllegalArgumentException: %s is not a valid argument value for the 'which' parameter.", decodeWhich(whichJInt))
			;
			throwIllegalArgumentException(env, "%s is not a valid argument value for the 'which' parameter.", decodeWhich(whichJInt));
			break;
	}
}
