CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

set(PROJ_NAME "cprojcreate")

include_directories(./)

file(GLOB SRC
        "main.c"
)

add_executable(${PROJ_NAME} ${SRC})
