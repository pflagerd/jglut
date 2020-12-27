#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutWireTeaspoon(JNIEnv *env, jobject object, jdouble size) {
    DPRINTF("glutWireTeaspoon(%.17g%s);\n", size, size == (int)size ? ".0" : "");
#ifdef WIN32
    jclass notImplementedException = (*env)->FindClass(env, "com/pflager/glut$NotImplementedException");
    DPRINTF("notImplementedException == %p\n", notImplementedException);
    (*env)->ThrowNew(env, notImplementedException, "glutWireTeaspoon() not implemented on Windows in this version.");
#else
    glutWireTeaspoon(size);
#endif
}
