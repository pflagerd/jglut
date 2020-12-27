#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_glut_glutMainLoop(JNIEnv *env, jobject object) {
	DPRINTF("glutMainLoop()\n");
	glutMainLoop();
}
