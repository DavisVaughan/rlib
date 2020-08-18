#' Length
#'
#' @description
#' - `r_length()` computes the length of `x`. This returns a `r_ssize_t`
#'   and supports long vectors.
#'
#' - `r_short_length()` computes the old style length of `x`. This returns a
#'   `r_short_ssize_t` and does not support long vectors.
#'
#' @param x A sexp to compute the length of.
#'
#' @return
#' For `r_length()`, a `r_ssize_t` containing the length of `x`.
#'
#' For `r_short_length()`, a `r_short_ssize_t` containing the
#' short length of `x`.
#'
#' @name
#'   r_length
#' @aliases
#'   r_short_length
NULL
