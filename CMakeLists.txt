CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

set(PROJ_NAME "cprojcreate")
set(CMAKE_TOOLCHAIN_FILE toolchain.cmake)
project(${PROJ_NAME})
include_directories(./)

file(GLOB SRC
    "main.c"
)

add_executable(${PROJ_NAME} ${SRC})
