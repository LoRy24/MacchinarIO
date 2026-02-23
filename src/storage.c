//
// Created by Lorenzo on 21/02/2026.
//

#include "../includes/storage.h"

#include <dirent.h>
#include <errno.h>

#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(path) _mkdir(path)
#else
    #include <sys/stat.h>
#define MKDIR(path) mkdir(path, 0755)
#endif

void fix_data_folder() {
    DIR* dir = opendir("data");
    if (dir) {
        closedir(dir);
    }
    else if (ENOENT == errno) {
        // Crea la cartella
        MKDIR("data");
    }
}
