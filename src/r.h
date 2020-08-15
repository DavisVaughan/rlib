#ifndef RLIB_R_H
#define RLIB_R_H


#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>
#include <stdbool.h>


typedef SEXP sexp;

typedef Rbyte r_byte_t;
typedef Rcomplex r_complex_t;

typedef R_xlen_t r_ssize_t;
#define R_SSIZE_T_MAX R_XLEN_T_MAX
typedef R_len_t r_short_ssize_t;
#define R_SHORT_SSIZE_T_MAX R_LEN_T_MAX

#define r_null R_NilValue

#define KEEP PROTECT
#define FREE UNPROTECT

#define KEEP_N(x, n) (++n, KEEP(x))

#define KEEP_WITH_INDEX(x, p_i) PROTECT_WITH_INDEX(x, p_i)
#define REKEEP REPROTECT


#endif
