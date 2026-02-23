//
// Created by Lorenzo on 21/02/2026.
//

#include "../includes/storage.h"

#include <errno.h>

#ifdef _WIN32
    #include <direct.h>
    #include <windows.h>
    #define MKDIR(path) _mkdir(path)
#else
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <dirent.h>
    #define MKDIR(path) mkdir(path, 0755)
#endif

void fix_data_folder() {
#ifdef _WIN32
    const DWORD ftyp = GetFileAttributesA("data");
    if (ftyp == INVALID_FILE_ATTRIBUTES) {
        MKDIR("data");
    }
#else
    DIR* dir = opendir("data");
    if (dir) {
        closedir(dir);
    } else if (errno == ENOENT) {
        MKDIR("data");
    }
#endif
}
