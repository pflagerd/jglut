#include <stdarg.h>
#include <stdio.h>

#include <pthread.h>
#include "DPRINTF.h"


unsigned char _DPRINTF_DEBUG_ = 1; // If non-zero, DPRINTF prints.

int _DPRINTF_(const char* file, int line, const char* fmt, ...) {
	if (!_DPRINTF_DEBUG_)
		return 0;

	printf("%s(%d):", file, line);

	#ifdef __linux__
		printf(" (pthread_t)%lx: ", pthread_self());
	#endif

	va_list (args);
	va_start(args, fmt);
	int retval = vprintf(fmt, args);
	va_end(args);
	fflush(stdout);
	return retval;
}

