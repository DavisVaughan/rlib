#ifndef RLIB_PRINT_H
#define RLIB_PRINT_H


#include "r.h"


#define r_printf Rprintf

static inline void r_print_sexp(sexp x) {
  Rf_PrintValue(x);
}


#endif
