#include <assert.h>
#include <stdio.h>

#include "arrayOfDoublesToString.h"

const char* arrayOfDoublesToString(double* array, size_t length) {
	static char s[32768];

	char* p = s;
	p += sprintf(p, "{ ");
	for (unsigned i = 0; i < length; i++) {
		if (i > 0) {
			p += sprintf(p, ", ");
		}
		p += sprintf(p, "%.17g", array[i]);
	}
	p += sprintf(p, " }");
	return s;
}
