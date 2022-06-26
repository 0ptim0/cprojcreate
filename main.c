#include <stdio.h>
#include <string.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>

#include "files.h"

int main(int argc, char **argv) {
    FILE *file;

    // Args parsing
    if(argc != 4 ) {
        printf("Wrong number of args!\n");
        printf("cprojcreate [name] [path_to_proj] [type]\n");
        printf("Example:\n");
        printf("cprojcreate empty ~/project cpp\n");
        return -1;
    }

    char *name = argv[1];
    char *path = argv[2];
    char *type = argv[3];
    char *cmake = "CMakeLists.txt";
    char *launch = "launch.json";

    // Check type
    if(!strcmp(type, "c") && !strcmp(type, "cpp")) {
        printf("Bad type, use c/cpp\n");
        printf("\n%s\n", type);
        return -1;
    }

    // Get path
    char path_proj[32];
    size_t len = strlen(path);
    strcpy(path_proj, path);
    if(path[len - 1] != '/') {
        strncat(path_proj, "/", 2);
    }
    path = path_proj;

    strncat(path, name, strlen(name));

    DIR *dir = opendir(path);

    // Check dir
    if(dir != NULL) {
        char answer;
        printf("Directory already exist.\n");
        printf("Overwrite? [Y/n]: ");
        answer = getchar();
        getchar();
        if(answer != 'Y') {
            return -1;
        } else {
            if(rmdir(path)) {
                perror("rmdir");
                printf("Delete all files in this directory? [Y/n]: ");
                answer = getchar();
                getchar();
                if(answer != 'Y') {
                    return -1;
                } else {
                    // TODO add recursive delete all files
                }
            }
        }
    }

    // Create directories
    mode_t dir_perm = S_IRUSR | S_IWUSR | S_IXUSR |
                      S_IRGRP | S_IWGRP | S_IXGRP |
                      S_IROTH | S_IXOTH;

    mkdir(path, dir_perm);
    chdir(path);
    mkdir(".vscode", dir_perm);

    // Generate main.c/main.cpp
    char *main_src;
    char *cmake_src_end;
    if(!strcmp(type, "cpp")) {
        file = fopen("main.cpp", "w");
        main_src = main_cpp_src;
        cmake_src_end = cmake_cpp_src_end;
    } else {
        file = fopen("main.c", "w");
        main_src = main_c_src;
        cmake_src_end = cmake_c_src_end;
    }

    if(file == NULL) {
        perror("main");
        return -1;
    }

    fwrite(main_src, 1, strlen(main_src), file);
    fclose(file);

    // Generate CMakeLists.txt
    file = fopen("CMakeLists.txt", "w");

    if(file == NULL) {
        perror("CMakeLists.txt");
        return -1;
    }

    fwrite(cmake_src_start, 1, strlen(cmake_src_start), file);
    fwrite(name, 1, strlen(name), file);
    fwrite(cmake_src_end, 1, strlen(cmake_src_end), file);
    fclose(file);

    // Generate launch.json
    file = fopen(".vscode/launch.json", "w");

    if(file == NULL) {
        perror("launch.json");
        return -1;
    }

    fwrite(launch_json_start, 1, strlen(launch_json_start), file);
    fwrite(name, 1, strlen(name), file);
    fwrite(launch_json_end, 1, strlen(launch_json_end), file);
    fclose(file);

    printf("Project successfuly generated!\n");

}
