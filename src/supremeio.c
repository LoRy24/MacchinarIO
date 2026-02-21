//
// Created by Lorenzo Rocca on 19/02/26.
//

#include <stdio.h>
#include <stdlib.h>

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

void clear_screen_cp() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

char* input_password_cp(const int maxSize, const bool printCensor, const char censorCharacter) {
    if (maxSize <= 0) return nullptr;

    // Crea il buffer
    char* buffer = malloc((maxSize + 1) * sizeof(char));
    if (!buffer) return nullptr;

    int index = 0;

    while (1) {
        const int ch = get_pressed_key_cp();

        // Invio
#ifdef _WIN32
        if (ch == 13) break;
#else
        if (ch == '\n') break;
#endif

        // Backspace
        if (ch == 8 || ch == 127) {
            if (index > 0) {
                index--;
                if (printCensor) {
                    printf("\b \b");
                    fflush(stdout);
                }
            }
        }
        // Carattere
        else if (ch >= 32 && ch <= 126) {
            if (index < maxSize) {
                buffer[index++] = (char)ch;

                if (printCensor) {
                    printf("%c", censorCharacter);
                    fflush(stdout);
                }
            }
        }
    }

    buffer[index] = '\0';
    printf("\n");
    return buffer;
}