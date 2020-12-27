#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_glut.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutInitDisplayMode(JNIEnv *env, jobject object, jint displayMode) {
	DPRINTF("glutInitDisplayMode(0x%08x)\n", displayMode);
	glutInitDisplayMode(displayMode);
}
