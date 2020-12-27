#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutInitWindowSize(JNIEnv *env, jobject object, jint width, jint height) {
	DPRINTF("glutInitWindowSize(%d, %d)\n", width, height);
	glutInitWindowSize(width, height);
}
