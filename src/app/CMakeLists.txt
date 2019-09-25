cmake_minimum_required(VERSION 3.5)
aux_source_directory(. DIR_APP_SRCS)

#LINK_LIBRARIES("/usr/lib/x86_64-linux-gnu/libboost_system.so")
#LINK_LIBRARIES("/usr/lib/x86_64-linux-gnu/libfftw3.so")
LINK_LIBRARIES("/usr/lib/x86_64-linux-gnu/libuhd.so")

add_library(app ${DIR_APP_SRCS})

#SET(CMAKE_EXE_LINKER_FLAGS "-L /usr/lib/x86_64-linux-gnu -lboost_system")
#SET(CMAKE_EXE_LINKER_FLAGS "-L /usr/lib/x86_64-linux-gnu -lfftw3")
#SET(CMAKE_EXE_LINKER_FLAGS "-L /usr/local/lib -luhd")
#target_link_libraries(libfftw3.so  libboost_system.so  libuhd.so)
