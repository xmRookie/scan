cmake_minimum_required(VERSION 3.5)
aux_source_directory(. DIR_DSP_SRCS)

FIND_LIBRARY(UHDLIB_LIBRARY libuhd.so)
message("uhd_path: ${UHDLIB_LIBRARY}")

LINK_LIBRARIES("/usr/lib/x86_64-linux-gnu/libboost_system.so")
LINK_LIBRARIES("/usr/lib/x86_64-linux-gnu/libfftw3.so")
#LINK_LIBRARIES("/usr/local/lib/libuhd.so")
LINK_LIBRARIES("${UHDLIB_LIBRARY}")

add_library(dsp ${DIR_DSP_SRCS})

