#include <assert.h>
#include <stdio.h>

#include "jglut.h"

#include "com_pflager_gl.h"

//
// Returns the number of elements in the array associated with pname.
//
int array_length_from_pname(int pname) {
	switch (pname) {
		case GL_AMBIENT:
			return 4;

		case GL_AMBIENT_AND_DIFFUSE:
			return 4;

		case GL_CONSTANT_ATTENUATION:
			return 1;

		case GL_COLOR_INDEXES:
			return 3;

		case GL_CURRENT_COLOR:
			return 4;

		case GL_DIFFUSE:
			return 4;

		case GL_EMISSION:
			return 4;

		case GL_EYE_PLANE:
			return 4;

		case GL_FOG_MODE:
			return 1;

		case GL_FOG_DENSITY:
			return 1;

		case GL_FOG_COLOR:
			return 4;

		case GL_FOG_INDEX:
			return 1;

		case GL_FOG_START:
			return 1;

		case GL_FOG_END:
			return 1;

		case GL_LINEAR:
			return 1;

		case GL_EXP:
			return 1;

		case GL_EXP2:
			return 1;

		case GL_LINEAR_ATTENUATION:
			return 1;

		case GL_LIGHT_MODEL_AMBIENT:
			return 4;

		case GL_LIGHT_MODEL_LOCAL_VIEWER:
			return 1;

		case GL_LIGHT_MODEL_TWO_SIDE:
			return 1;

		case GL_MODELVIEW_MATRIX: {
			GLint stack_depth = 0;
			glGetIntegerv(GL_MODELVIEW_STACK_DEPTH, &stack_depth);
			DPRINTF("GL_MODELVIEW_STACK_DEPTH: %d\n", stack_depth);
			return stack_depth * 16;
		}

		case GL_OBJECT_PLANE:
			return 4;

		case GL_POSITION:
			return 4;

		case GL_PROJECTION_MATRIX: {
			GLint stack_depth = 0;
			glGetIntegerv(GL_PROJECTION_STACK_DEPTH, &stack_depth);
			DPRINTF("GL_PROJECTION_STACK_DEPTH: %d\n", stack_depth);
			return stack_depth * 16;
		}

		case GL_QUADRATIC_ATTENUATION:
			return 1;

		case GL_SHININESS:
			return 1;

		case GL_SPECULAR:
			return 4;

		case GL_SPOT_CUTOFF:
			return 1;

		case GL_SPOT_DIRECTION:
			return 3;

		case GL_SPOT_EXPONENT:
			return 1;

		case GL_TEXTURE_GEN_MODE:
			return 1;

		case GL_VIEWPORT:
			return 4;

		default:
			break;
	}
	return 0;
}

