#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

PASTE_SIGNATURE_HERE {
	DPRINTF("glutSomething()\n");

    jclass notImplementedException = (*env)->FindClass(env, "com/pflager/glut$NotImplementedException");
    DPRINTF("notImplementedException == %p\n", notImplementedException);
    (*env)->ThrowNew(env, notImplementedException, "glutSomething()");
    return;
}
