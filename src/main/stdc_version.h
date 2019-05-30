#ifndef STDC_VERSION_H
#define STDC_VERSION_H

#if __STDC_VERSION__ >= 199901L
#include <stdint.h>

#else
#error "Use C99 or later"

#endif

#endif // STDC_VERSION_H
