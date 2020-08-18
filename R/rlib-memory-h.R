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
#' @name
#'   r_mark_precious
#' @aliases
#'   r_unmark_precious
NULL
