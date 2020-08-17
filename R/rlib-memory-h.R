#' Protect objects from garbage collection
#'
#' @description
#' - `r_mark_precious()` protects `x` from being garbage collected.
#'
#' - `r_unmark_precious()` releases a protected sexp to allow it to be
#'   garbage collected.
#'
#' @param x A sexp.
#'
#' @fn r_mark_precious
#' @args x
#' @export
r_mark_precious <- function(x) {}

#' @rdname r_mark_precious
#' @fn r_unmark_precious
#' @args x
#' @export
r_unmark_precious <- function(x) {}
