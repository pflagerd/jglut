#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glCopyPixels(JNIEnv *env, jobject object, jint xJInt, jint yJInt, jint widthJInt, jint heightJInt, jint typeJInt) {
    DPRINTF("glCopyPixels(%d, %d, %d, %d, %d);\n", xJInt, yJInt, widthJInt, heightJInt, typeJInt);
    glCopyPixels(xJInt, yJInt, widthJInt, heightJInt, typeJInt);

}
