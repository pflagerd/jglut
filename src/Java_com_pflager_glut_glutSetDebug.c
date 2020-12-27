#include "jglut.h"

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutSetDebug(JNIEnv *env, jobject object, jboolean debugJBoolean) {
    DPRINTF("glutSetDebug(%d);\n", debugJBoolean);

    _DPRINTF_DEBUG_ = debugJBoolean;
}
