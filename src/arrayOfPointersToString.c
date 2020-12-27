#include <assert.h>
#include <stdio.h>

#include "arrayOfPointersToString.h"

const char* arrayOfPointersToString(void** array, size_t length) {
	static char s[32768];

	char* p = s;
	p += sprintf(p, "{ ");
	for (unsigned i = 0; i < length; i++) {
		if (i > 0) {
			p += sprintf(p, ", ");
		}
		p += sprintf(p, "%p", array[i]);
	}
	p += sprintf(p, " }");
	return s;
}
