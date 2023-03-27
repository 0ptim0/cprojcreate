const char main_c_src[] = "\
#include <stdio.h>\n\
\n\
int main(int argc, char *argv[]) {\n\
    return 0;\n\
}\n\
";

const char main_cpp_src[] = "\
#include <iostream>\n\
using namespace std;\n\
\n\
int main(int argc, char *argv[]) {\n\
    return 0;\n\
}\n\
";

const char cmake_src_start[] = "\
CMAKE_MINIMUM_REQUIRED(VERSION 3.15)\n\
\n\
set(PROJ_NAME ";

const char cmake_cpp_src_end[] = ")\n\
\n\
set(CMAKE_TOOLCHAIN_FILE toolchain.cmake)\n\
project(${PROJ_NAME})\n\
include_directories(./)\n\
\n\
file(GLOB SRC\n\
    \"main.cpp\"\n\
)\n\
\n\
add_executable(${PROJ_NAME} ${SRC})\n";

const char cmake_c_src_end[] = ")\n\
\n\
set(CMAKE_TOOLCHAIN_FILE toolchain.cmake)\n\
project(${PROJ_NAME})\n\
include_directories(./)\n\
\n\
file(GLOB SRC\n\
    \"main.c\"\n\
)\n\
\n\
add_executable(${PROJ_NAME} ${SRC})\n";

const char launch_json_start[] = "\
{\n\
    \"version\": \"2.0.0\",\n\
    \"configurations\": [\n\
        {\n\
            \"name\": \"UNIX\",\n\
            \"type\": \"cppdbg\",\n\
            \"request\": \"launch\",\n\
            \"program\": \"${workspaceFolder}/build/";

const char launch_json_end[] = "\",\n\
            \"args\": [],\n\
            \"stopAtEntry\": false,\n\
            \"cwd\": \"${workspaceFolder}\",\n\
            \"environment\": [],\n\
            \"externalConsole\": false,\n\
            \"MIMode\": \"gdb\",\n\
            \"setupCommands\": [\n\
                {\n\
                    \"description\": \"Enable pretty-printing for gdb\",\n\
                    \"text\": \"-enable-pretty-printing\",\n\
                    \"ignoreFailures\": true\n\
                }\n\
            ],\n\
            \"miDebuggerPath\": \"/usr/bin/gdb\",\n\
        }\n\
    ]\n\
}\n\
";

const char clang_format[] = "BasedOnStyle: Google\n\
IndentWidth: 4\n\
ColumnLimit: 80\n\
AlignAfterOpenBracket: Align\n\
AllowShortFunctionsOnASingleLine: Inline\n\
AccessModifierOffset: -4\n\
";

const char toolchain[] = "cmake_minimum_required(VERSION 3.6)\n\
\n\
set(TOOLCHAIN Linux)\n\
set(CMAKE_SYSTEM_NAME Linux)\n\
set(CMAKE_SYSTEM_PROCESSOR x86)\n\
set(CMAKE_SYSTEM_VERSION 1)\n\
\n\
SET(CMAKE_C_COMPILER_WORKS   TRUE)\n\
SET(CMAKE_CXX_COMPILER_WORKS TRUE)\n\
\n\
set(CMAKE_C_COMPILER   /bin/gcc)\n\
set(CMAKE_CXX_COMPILER /bin/g++)\n\
set(CMAKE_ASM_COMPILER /bin/gcc)\n\
set(CMAKE_SIZE         /bin/size)\n\
set(CMAKE_OBJCOPY      /bin/objcopy)\n\
set(CMAKE_OBJDUMP      /bin/objdump)\n\
\n\
string(CONCAT COMPILER_FLAGS\n\
    \"${MCU_FLAGS} \"\n\
    \"-Werror -pedantic-errors \"\n\
    \"-Wall -Wextra \"\n\
    \"-Wpedantic \"\n\
    \"-Wcast-align \"\n\
    \"-Wcast-qual \"\n\
    \"-Wduplicated-branches \"\n\
    \"-Wduplicated-cond \"\n\
    \"-Wfloat-equal \"\n\
    \"-Wlogical-op \"\n\
    \"-Wredundant-decls \"\n\
    \"-Wsign-conversion \"\n\
    \"-Wconversion \"\n\
    \"-Wno-unused-variable -Wno-unused-function -Wno-unused-parameter -Wno-missing-braces \"\n\
)\n\
\n\
set(CMAKE_C_FLAGS_DEBUG \"-O0 -g3 ${COMPILER_FLAGS}\")\n\
set(CMAKE_C_FLAGS_RELEASE \"-O3 -DNDEBUG ${COMPILER_FLAGS}\")\n\
set(CMAKE_CXX_FLAGS_DEBUG \"-O0 -g3 ${COMPILER_FLAGS}\")\n\
set(CMAKE_CXX_FLAGS_RELEASE \"-O3 -DNDEBUG ${COMPILER_FLAGS}\")\n\
";
