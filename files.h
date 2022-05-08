static char *main_src = "\
#include <stdio.h>\n\
\n\
int main (int argc, char **argv) {\n\
\n\
}\n\
";

static char *cmake_src_start = "\
CMAKE_MINIMUM_REQUIRED(VERSION 3.15)\n\
\n\
set(PROJ_NAME ";

static char *cmake_src_end = ")\n\
\n\
include_directories(./)\n\
\n\
file(GLOB SRC\n\
    \"main.c\"\n\
)\n\
\n\
add_executable(${PROJ_NAME} ${SRC})\n";

static char *launch_json_start = "\
{\n\
    \"version\": \"2.0.0\",\n\
    \"configurations\": [\n\
        {\n\
            \"name\": \"UNIX\",\n\
            \"type\": \"cppdbg\",\n\
            \"request\": \"launch\",\n\
            \"program\": \"${workspaceFolder}/build/";

static char *launch_json_end = "\",\n\
            \"args\": [\"fuck\", \"~/optim\"], // [\"arg1\", \"arg2\"]\n\
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
