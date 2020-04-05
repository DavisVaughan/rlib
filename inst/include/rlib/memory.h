#ifndef RLIB_MEMORY_H
#define RLIB_MEMORY_H


#include "r.h"


#define KEEP PROTECT
#define FREE UNPROTECT

#define KEEP_N(x, n) (++n, KEEP(x))

#define KEEP_WITH_INDEX(x, i) PROTECT_WITH_INDEX(x, &i)
#define REKEEP REPROTECT


#endif
