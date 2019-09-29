cmake_minimum_required(VERSION 3.5)

project(scan)

# Add the source in project root directory
#aux_source_directory(. DIRSRCS)
#包含主文件夹下的main.cpp文件

# Add header file include directories
include_directories(./ ./app ./dsp)
#添加多目录的路径

# Add block directories

add_subdirectory(app)
#添加app文件夹中的app库

add_subdirectory(dsp)
#添加dsp文件夹中的dsp库

add_executable(scan main.cpp)

FIND_LIBRARY(UHDLIB_LIBRARY libuhd.so)
message("uhd_path: ${UHDLIB_LIBRARY}")

LINK_LIBRARIES("/usr/lib/x86_64-linux-gnu/libboost_system.so")
LINK_LIBRARIES("/usr/lib/x86_64-linux-gnu/libfftw3.so")
#LINK_LIBRARIES("/usr/local/lib/libuhd.so")
LINK_LIBRARIES("${UHDLIB_LIBRARY}")

target_link_libraries(scan app dsp)
#将多目录下的app库和dsp库链接上可执行文件scan.o


