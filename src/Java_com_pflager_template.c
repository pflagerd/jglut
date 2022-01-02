#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

void PASTE_SIGNATURE_HERE(JNIEnv *env, jobject object) {
	DPRINTF("glutSomething()\n");

    jclass notImplementedException = (*env)->FindClass(env, "com/pflager/glut$NotImplementedException");
    DPRINTF("notImplementedException == %p\n", notImplementedException);
    (*env)->ThrowNew(env, notImplementedException, "glutSomething()");
    return;
}
