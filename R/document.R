rlib_document <- function(path = ".") {
  path <- pkg_path(path)

  dir_src <- file.path(path, "src")

  # Find `src/` files that may have comments
  files <- dir(dir_src, recursive = TRUE, full.names = TRUE)
  files <- filter_files(files)

  # Construct names in `R/`
  paths <- path_file(files)
  paths <- gsub("[.]", "-", paths)
  paths <- glue::glue("rlib-{paths}.R")
  paths <- file.path(path, "R", paths)

  comments <- lapply(files, read_comments)
  mapply(write_comments, comments, paths)

  devtools::document()
}

read_comments <- function(file) {
  lines <- readLines(file)

  comments <- grepl("^//'", lines)

  rle <- unclass(rle(comments))

  starts <- c(1L, rle$lengths)
  starts <- starts[-length(starts)]
  starts <- cumsum(starts)
  starts <- starts[rle$values]

  stops <- rle$lengths
  stops <- cumsum(stops)
  stops <- stops[rle$values]

  blocks <- vector("list", length = length(starts))

  for (i in seq_along(starts)) {
    start <- starts[[i]]
    stop <- stops[[i]]

    seq <- rlang::seq2(start, stop)

    block <- lines[seq]
    block <- gsub("//'", "#'", block)

    block <- c(block, "NULL")
    block <- glue::glue_collapse(block, sep = "\n")
    block <- as.character(block)

    blocks[[i]] <- block
  }

  lines <- vctrs::vec_unchop(blocks, ptype = character())
  lines <- glue::glue_collapse(lines, sep = "\n\n")
  lines <- as.character(lines)

  lines
}

write_comments <- function(lines, path) {
  if (file.exists(path)) {
    file.remove(path)
  }

  if (length(lines) == 0L) {
    return()
  }

  success <- file.create(path)
  if (!success) {
    rlang::abort("File creation failed.")
  }

  writeLines(lines, path)
}

filter_files <- function(x) {
  # Only `.c` and `.h` files
  filter <- grepl("[.]c", x) | grepl("[.]h", x)

  # Not `init.c`
  filter[grepl("init[.]c", x)] <- FALSE

  x[filter]
}

pkg_path <- function (path = ".") {
  rprojroot::find_root("DESCRIPTION", path)
}

# fs::path_file()
path_file <- function (path) {
  is_missing <- is.na(path)
  path[!is_missing] <- basename(path[!is_missing])
  as.character(path)
}

#' @export
roxy_tag_parse.roxy_tag_fn <- function(x) {
  roxygen2::tag_value(x)
}

#' @export
roxy_tag_parse.roxy_tag_args <- function(x) {
  roxygen2::tag_value(x)
}
