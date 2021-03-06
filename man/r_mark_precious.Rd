% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/rlib-memory-h.R
\name{r_mark_precious}
\alias{r_mark_precious}
\alias{r_unmark_precious}
\title{Protect objects from garbage collection}
\arguments{
\item{x}{A sexp.}
}
\description{
\itemize{
\item \code{r_mark_precious()} protects \code{x} from being garbage collected.
\item \code{r_unmark_precious()} releases a protected sexp to allow it to be
garbage collected.
}
}
