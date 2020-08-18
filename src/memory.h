#ifndef RLIB_MEMORY_H
#define RLIB_MEMORY_H


#include "r.h"

// -----------------------------------------------------------------------------

//' Protect objects from garbage collection
//'
//' @description
//' - `r_mark_precious()` protects `x` from being garbage collected.
//'
//' - `r_unmark_precious()` releases a protected sexp to allow it to be
//'   garbage collected.
//'
//' @param x A sexp.
//'
//' @name
//'   r_mark_precious
//' @aliases
//'   r_unmark_precious
static inline void r_mark_precious(sexp x) {
  R_PreserveObject(x);
}
static inline void r_unmark_precious(sexp x) {
  R_ReleaseObject(x);
}

// -----------------------------------------------------------------------------

static inline void r_mark_shared(sexp x) {
  MARK_NOT_MUTABLE(x);
}
static inline bool r_is_shared(sexp x) {
  return MAYBE_SHARED(x);
}
static inline bool r_is_referenced(sexp x) {
  return MAYBE_REFERENCED(x);
}

// -----------------------------------------------------------------------------

static inline sexp r_copy(sexp x) {
  return Rf_duplicate(x);
}
static inline sexp r_clone(sexp x) {
  return Rf_shallow_duplicate(x);
}

// -----------------------------------------------------------------------------

static inline sexp r_clone_referenced(sexp x) {
  if (r_is_referenced(x)) {
    return r_clone(x);
  } else {
    return x;
  }
}
static inline sexp r_clone_shared(sexp x) {
  if (r_is_shared(x)) {
    return r_clone(x);
  } else {
    return x;
  }
}

#endif
