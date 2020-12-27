#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutInitWindowPosition(JNIEnv *env, jobject object, jint x, jint y) {
	DPRINTF("glutInitWindowPosition(%d, %d)\n", x, y);
	glutInitWindowPosition(x, y);
}
