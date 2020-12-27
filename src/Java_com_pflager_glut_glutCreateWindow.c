#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_glut.h"

JNIEXPORT jint JNICALL Java_com_pflager_glut_glutCreateWindow(JNIEnv* env, jobject object, jstring title) {

	const char* title_cstr = (*env)->GetStringUTFChars(env, title, NULL);

	DPRINTF("glutCreateWindow(\"%s\")", title_cstr);

	jint ret_jint = glutCreateWindow(title_cstr);

	(*env)->ReleaseStringUTFChars(env, title, title_cstr);

	DPRINTF(" => %d\n", ret_jint);

	return ret_jint;
}
