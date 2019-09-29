cmake_minimum_required(VERSION 3.5)
aux_source_directory(. DIR_APP_SRCS)

FIND_LIBRARY(UHDLIB_LIBRARY libuhd.so)
message("uhd_path: ${UHDLIB_LIBRARY}")

#LINK_LIBRARIES("/usr/local/lib/libuhd.so")
LINK_LIBRARIES("${UHDLIB_LIBRARY}")

add_library(app ${DIR_APP_SRCS})

