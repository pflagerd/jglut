#include <assert.h>
#include <stdio.h>

#include <jglut.h>

#include "com_pflager_gl.h"

JNIEXPORT void JNICALL Java_com_pflager_gl_glRectf__DDDD(JNIEnv* env, jobject object, jdouble x1, jdouble y1, jdouble x2, jdouble y2) {
	DPRINTF("glRectf(%.17g%s, %.17g%s, %.17g%s, %.17g%s)\n", x1, (x1 == (int)x1) ? ".0" : "", y1, (y1 == (int)y1) ? ".0" : "", x2, (x2 == (int)x2) ? ".0" : "", y2, (y2 == (int)y2) ? ".0" : "");
	glRectd(x1, y1, x2, y2);
}
