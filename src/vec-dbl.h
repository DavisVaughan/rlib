#ifndef RLIB_VEC_DBL_H
#define RLIB_VEC_DBL_H


#include "r.h"
#include "type.h"
#include "vec.h"


static inline sexp r_new_dbl(r_ssize_t n) {
  return r_new_vector(r_type_double, n);
}
static inline sexp r_new_scalar_dbl(double x) {
  return Rf_ScalarReal(x);
}


static inline double* r_dbl_deref(sexp x) {
  return REAL(x);
}
static inline const double* r_dbl_const_deref(sexp x) {
  return (const double*) r_dbl_deref(x);
}


#endif
