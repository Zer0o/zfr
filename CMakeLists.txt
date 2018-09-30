cmake_minimum_required(VERSION 2.8)
project(zfr)
set(CMAKE_INSTALL_PREFIX ../bin)
aux_source_directory(. SRCS)
aux_source_directory(src SRCS)
add_executable(zfr ${SRCS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -O3 -g -minline-all-stringops -pipe -Wall -Werror -Wno-deprecated -Wno-unused-variable -Werror=strict-aliasing -lrt -pthread")

include_directories(src)
install(TARGETS zfr RUNTIME DESTINATION .)
