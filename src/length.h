#ifndef RLIB_LENGTH_H
#define RLIB_LENGTH_H


#include "r.h"


static inline r_ssize_t r_length(sexp x) {
  return Rf_xlength(x);
}
static inline r_short_ssize_t r_short_length(sexp x) {
  return Rf_length(x);
}


#endif
