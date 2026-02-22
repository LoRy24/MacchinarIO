//
// Created by Lorenzo on 21/02/2026.
//

#include "../includes/storage.h"

#include <dirent.h>
#include <errno.h>

void fix_data_folder() {
    DIR* dir = opendir("data");
    if (dir) {
        closedir(dir);
    }
    else if (ENOENT == errno) {
        // Crea la cartella
        mkdir("data");
    }
}
