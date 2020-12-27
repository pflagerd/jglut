#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <jglut.h>

#include "com_pflager_gl.h"

extern void* glColorPointer_doublebuffer;
extern void* glColorPointer_floatbuffer;
extern void* glColorPointer_intbuffer;
extern void* glColorPointer_shortbuffer;
extern void* glInterleavedArrays_doublebuffer;
extern void* glInterleavedArrays_floatbuffer;
extern void* glInterleavedArrays_intbuffer;
// NOTE: There is no extern void* glInterleavedArrays_shortbuffer;
extern void* glVertexPointer_doublebuffer;
extern void* glVertexPointer_floatbuffer;
extern void* glVertexPointer_intbuffer;
extern void* glVertexPointer_shortbuffer;

JNIEXPORT void JNICALL Java_com_pflager_gl_DisposeResources(JNIEnv *env, jclass jClass) {
	DPRINTF("DisposeResources();");

	if (glColorPointer_doublebuffer) {
		DPRINTF("Freeing glColorPointer_doublebuffer");
		free(glColorPointer_doublebuffer);
	}

	if (glColorPointer_floatbuffer) {
		DPRINTF("Freeing glColorPointer_floatbuffer");
		free(glColorPointer_floatbuffer);
	}

	if (glColorPointer_intbuffer) {
		DPRINTF("Freeing glColorPointer_intbuffer");
		free(glColorPointer_intbuffer);
	}

	if (glColorPointer_shortbuffer) {
		DPRINTF("Freeing glColorPointer_shortbuffer");
		free(glColorPointer_shortbuffer);
	}

	if (glInterleavedArrays_doublebuffer) {
		DPRINTF("Freeing glInterleavedArrays_doublebuffer");
		free(glInterleavedArrays_doublebuffer);
	}

	if (glInterleavedArrays_floatbuffer) {
		DPRINTF("Freeing glInterleavedArrays_floatbuffer");
		free(glInterleavedArrays_floatbuffer);
	}

	if (glInterleavedArrays_intbuffer) {
		DPRINTF("Freeing glInterleavedArrays_intbuffer");
		free(glInterleavedArrays_intbuffer);
	}

	/* NOTE: There is no glInterleavedArrays_shortbuffer, because all format arguments to glInterleavedArrays() deal with 32-bit array elements.
	if (glInterleavedArrays_shortbuffer) {
		DPRINTF("Freeing glInterleavedArrays_shortbuffer");
		free(glInterleavedArrays_shortbuffer);
	}
	*/

	if (glVertexPointer_doublebuffer) {
		DPRINTF("Freeing glVertexPointer_doublebuffer");
		free(glVertexPointer_doublebuffer);
	}

	if (glVertexPointer_floatbuffer) {
		DPRINTF("Freeing glVertexPointer_floatbuffer");
		free(glVertexPointer_floatbuffer);
	}

	if (glVertexPointer_intbuffer) {
		DPRINTF("Freeing glVertexPointer_intbuffer");
		free(glVertexPointer_intbuffer);
	}

	if (glVertexPointer_shortbuffer) {
		DPRINTF("Freeing glVertexPointer_shortbuffer");
		free(glVertexPointer_shortbuffer);
	}
}
