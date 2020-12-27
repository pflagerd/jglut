#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_glut.h"

void* fontMap[] = {
	GLUT_STROKE_ROMAN,
	GLUT_STROKE_MONO_ROMAN,
	GLUT_BITMAP_9_BY_15,
	GLUT_BITMAP_8_BY_13,
	GLUT_BITMAP_TIMES_ROMAN_10,
	GLUT_BITMAP_TIMES_ROMAN_24,
	GLUT_BITMAP_HELVETICA_10,
	GLUT_BITMAP_HELVETICA_12,
	GLUT_BITMAP_HELVETICA_18,
};

JNIEXPORT void JNICALL Java_com_pflager_glut_glutBitmapCharacter(JNIEnv *env, jobject object, jint fontJInt, jchar characterJChar) {
    DPRINTF("glutBitmapCharacter(%d, %d);\n", fontJInt, characterJChar);
    glutBitmapCharacter(fontMap[fontJInt & 0x7], characterJChar);
}
