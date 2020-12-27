#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT jintArray JNICALL Java_com_pflager_gl_glGenTextures__I(JNIEnv *env, jobject object, jint nJInt) {
		DPRINTF("glGenTextures(%d);\n", nJInt);

	    if (nJInt <= 0) {
	        jclass illegalArgumentException = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
	        DPRINTF("illegalArgumentException == %p\n", illegalArgumentException);
	        (*env)->ThrowNew(env, illegalArgumentException, "You should pass n >= 0.");
	        return NULL;
	    }

	    GLuint GLuint_array[nJInt];

		glGenTextures(nJInt, GLuint_array);

		jintArray jIntArray = (*env)->NewIntArray(env, nJInt);  // allocate
		if (NULL == jIntArray) {
			return NULL;
		}

		(*env)->SetIntArrayRegion(env, jIntArray, 0 , nJInt, (jint*)GLuint_array);  // copy

		return jIntArray;
}
