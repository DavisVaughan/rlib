/**
 * @file vec-int.h
 * @brief Integer vector tooling
 */

#ifndef RLIB_VEC_INT_H
#define RLIB_VEC_INT_H


#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>


/**
 * Construct a new integer vector.
 *
 * @param length The length of the resulting vector.
 */
static inline SEXP r_new_int(R_xlen_t length) {
  return Rf_allocVector(INTSXP, length);
}

/**
 * Dereference an integer vector
 *
 * @param x The vector to dereference
 *
 * @return An integer pointer to the dereferenced vector.
 */
static inline int* r_int_deref(SEXP x) {
  return INTEGER(x);
}

#endif
