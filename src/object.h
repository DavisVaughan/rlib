#ifndef RLIB_OBJECT_H
#define RLIB_OBJECT_H


#include "r.h"


static inline void r_mark_object(sexp x) {
  SET_OBJECT(x, 1);
}
static inline void r_unmark_object(sexp x) {
  SET_OBJECT(x, 0);
}
static inline bool r_is_object(sexp x) {
  return OBJECT(x);
}

static inline bool r_inherits(sexp x, const char* tag) {
  return Rf_inherits(x, tag);
}


#endif
