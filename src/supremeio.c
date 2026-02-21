//
// Created by Lorenzo Rocca on 19/02/26.
//

#include <stdio.h>

#include "../includes/supremeio.h"

int get_pressed_key_cp() {
#ifdef _WIN32
    return _getch();
#else
    struct termios oldSettings, newSettings;
    tcgetattr(STDIN_FILENO, &oldSettings);
    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
    const int inputCharacter = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldSettings);
    return inputCharacter;
#endif
}