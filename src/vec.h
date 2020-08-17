#ifndef RLIB_VEC_H
#define RLIB_VEC_H

#include "r.h"
#include "type.h"

// -----------------------------------------------------------------------------

static inline sexp r_new_vector(enum r_type type, r_ssize_t n) {
  return Rf_allocVector(type, n);
}

static inline sexp r_new_lgl(r_ssize_t n) {
  return r_new_vector(r_type_logical, n);
}
static inline sexp r_new_int(r_ssize_t n) {
  return r_new_vector(r_type_integer, n);
}
static inline sexp r_new_dbl(r_ssize_t n) {
  return r_new_vector(r_type_double, n);
}
static inline sexp r_new_chr(r_ssize_t n) {
  return r_new_vector(r_type_character, n);
}
static inline sexp r_new_raw(r_ssize_t n) {
  return r_new_vector(r_type_raw, n);
}
static inline sexp r_new_cpl(r_ssize_t n) {
  return r_new_vector(r_type_complex, n);
}
static inline sexp r_new_lst(r_ssize_t n) {
  return r_new_vector(r_type_list, n);
}

// -----------------------------------------------------------------------------

static inline sexp r_new_scalar_lgl(int x) {
  return Rf_ScalarLogical(x);
}
static inline sexp r_new_scalar_int(int x) {
  return Rf_ScalarInteger(x);
}
static inline sexp r_new_scalar_dbl(double x) {
  return Rf_ScalarReal(x);
}
static inline sexp r_new_scalar_chr(sexp x) {
  return Rf_ScalarString(x);
}
static inline sexp r_new_scalar_raw(r_byte_t x) {
  return Rf_ScalarRaw(x);
}
static inline sexp r_new_scalar_cpl(r_complex_t x) {
  return Rf_ScalarComplex(x);
}
// static inline sexp r_new_scalar_lst(sexp x) {
//
// }

// -----------------------------------------------------------------------------

static inline int* r_lgl_deref(sexp x) {
  return LOGICAL(x);
}
static inline int* r_int_deref(sexp x) {
  return INTEGER(x);
}
static inline double* r_dbl_deref(sexp x) {
  return REAL(x);
}
// static inline sexp* r_chr_deref(sexp x) {
//   return STRING_PTR(x);
// }
static inline r_byte_t* r_raw_deref(sexp x) {
  return RAW(x);
}
static inline r_complex_t* r_cpl_deref(sexp x) {
  return COMPLEX(x);
}
// static inline sexp* r_lst_deref(sexp x) {
//   return VECTOR_PTR(x);
// }

static inline const int* r_lgl_const_deref(sexp x) {
  return LOGICAL_RO(x);
}
static inline const int* r_int_const_deref(sexp x) {
  return INTEGER_RO(x);
}
static inline const double* r_dbl_const_deref(sexp x) {
  return REAL_RO(x);
}
static inline const sexp* r_chr_const_deref(sexp x) {
  return STRING_PTR_RO(x);
}
static inline const r_byte_t* r_raw_const_deref(sexp x) {
  return RAW_RO(x);
}
static inline const r_complex_t* r_cpl_const_deref(sexp x) {
  return COMPLEX_RO(x);
}
static inline const sexp* r_lst_const_deref(sexp x) {
  return VECTOR_PTR_RO(x);
}

// -----------------------------------------------------------------------------

#endif
