#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <stdbool.h>
#include <R_ext/Rdynload.h>

// If you link to this library, compile with:
// `-fvisibility=hidden -DHAVE_VISIBILITY_ATTRIBUTE`
#include <R_ext/Visibility.h>
#define export attribute_visible extern

static const R_CallMethodDef CallEntries[] = {
  {NULL, NULL, 0}
};

export void R_init_rlib(DllInfo *dll) {
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
