#ifndef RLIB_VEC_H
#define RLIB_VEC_H


#include "r.h"
#include "type.h"


static inline sexp r_new_vector(enum r_type type, r_ssize_t n) {
  return Rf_allocVector(type, n);
}


#endif
