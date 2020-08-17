#ifndef RLIB_R_H
#define RLIB_R_H


#define R_NO_REMAP
#include <R.h>
#include <Rversion.h>
#include <Rinternals.h>
#include <stdbool.h>

// -----------------------------------------------------------------------------

typedef SEXP sexp;

typedef Rbyte r_byte_t;
typedef Rcomplex r_complex_t;

typedef R_xlen_t r_ssize_t;
#define R_SSIZE_T_MAX R_XLEN_T_MAX
typedef R_len_t r_short_ssize_t;
#define R_SHORT_SSIZE_T_MAX R_LEN_T_MAX

#define r_null R_NilValue

// -----------------------------------------------------------------------------

#define KEEP PROTECT
#define FREE UNPROTECT

#define KEEP_N(x, n) (++n, KEEP(x))

#define KEEP_WITH_INDEX(x, p_i) PROTECT_WITH_INDEX(x, p_i)
#define REKEEP REPROTECT

// -----------------------------------------------------------------------------
// Compatibility

#if (R_VERSION < R_Version(3, 5, 0))
# define DATAPTR_RO(x) ((const void*) DATAPTR(x))
# define LOGICAL_RO(x) ((const int*) LOGICAL(x))
# define INTEGER_RO(x) ((const int*) INTEGER(x))
# define REAL_RO(x) ((const double*) REAL(x))
# define COMPLEX_RO(x) ((const r_complex_t*) COMPLEX(x))
# define STRING_PTR_RO(x) ((const sexp*) STRING_PTR(x))
# define RAW_RO(x) ((const r_byte_t*) RAW(x))
#endif

// -----------------------------------------------------------------------------

// Const pointer for fast list access
#define VECTOR_PTR_RO(x) ((const sexp*) DATAPTR_RO(x))

// -----------------------------------------------------------------------------

#endif
