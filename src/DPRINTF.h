#ifndef DPRINTF_
#define DPRINTF_

#include <stdarg.h>

#ifndef DPRINTF
#if defined(NDEBUG)
#define DPRINTF(...)
#else
#define DPRINTF(args...) _DPRINTF_(__FILE__, __LINE__, args)
#endif
#endif

extern unsigned char _DPRINTF_DEBUG_;

int _DPRINTF_(const char* file, int line, const char* fmt, ...);

#endif // DPRINTF_
