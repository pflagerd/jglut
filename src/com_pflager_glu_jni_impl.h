#ifdef  _COM_PFLAGER_GLU_JNI_IMPL_
#define _COM_PFLAGER_GLU_JNI_IMPL_

#include "jglut.h"
#include "com_pflager_glu.h"

typedef struct com_pflager_glu_jni_impl {
	// GLUtesselator* glutesselator // TODO: DPP: 200203051712: For future expansion
	jobject dataJObjectGlobalReference[];
	size_t dataJObjectGlobalReferenceCurrentCapacity;
	size_t dataJObjectGlobalReferenceLength;
} com_pflager_glu_jni_impl;

#endif // _COM_PFLAGER_GLU_JNI_IMPL_
