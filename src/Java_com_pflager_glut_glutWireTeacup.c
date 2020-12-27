#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutWireTeacup(JNIEnv *env, jobject object, jdouble size) {
    DPRINTF("glutWireTeacup(%.17g%s);\n", size, size == (int)size ? ".0" : "");
#ifdef WIN32
    jclass notImplementedException = (*env)->FindClass(env, "com/pflager/glut$NotImplementedException");
    DPRINTF("notImplementedException == %p\n", notImplementedException);
    (*env)->ThrowNew(env, notImplementedException, "glutWireTeacup() not implemented on Windows in this version.");
#else
    glutWireTeacup(size);
#endif
}
