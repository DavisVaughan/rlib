#ifndef RLIB_TYPE_H
#define RLIB_TYPE_H


#include "r.h"


enum r_type {
  r_type_null        = 0,
  r_type_symbol      = 1,
  r_type_pairlist    = 2,
  r_type_closure     = 3,
  r_type_environment = 4,
  r_type_promise     = 5,
  r_type_call        = 6,
  r_type_special     = 7,
  r_type_builtin     = 8,
  r_type_string      = 9,
  r_type_logical     = 10,
  r_type_integer     = 13,
  r_type_double      = 14,
  r_type_complex     = 15,
  r_type_character   = 16,
  r_type_dots        = 17,
  r_type_any         = 18,
  r_type_list        = 19,
  r_type_expression  = 20,
  r_type_bytecode    = 21,
  r_type_pointer     = 22,
  r_type_weakref     = 23,
  r_type_raw         = 24,
  r_type_s4          = 25,

  r_type_new         = 30,
  r_type_free        = 31,

  r_type_function    = 99
};

static inline enum r_type r_type(sexp x) {
  return (enum r_type) TYPEOF(x);
}

static inline const char* r_type_as_c_string(enum r_type type) {
  return Rf_type2char(type);
}
static inline enum r_type r_type_from_c_string(const char* type) {
  return Rf_str2type(type);
}

static inline void r_poke_type(sexp x, enum r_type type) {
  SET_TYPEOF(x, type);
}
static inline void r_poke_type_from_c_string(sexp x, const char* type) {
  SET_TYPEOF(x, r_type_from_c_string(type));
}

static inline bool r_is_null(sexp x) {
  return x == r_null;
}


#endif
