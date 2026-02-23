//
// Created by Lorenzo Rocca on 19/02/26.
//

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
#endif

#include "../includes/supremeio.h"

int get_pressed_key_cp() {
#ifdef _WIN32
    return _getch();
#else
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    const int ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
#endif
}

void flush_stdin_cp() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void clear_screen_cp() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

char* input_password_cp(const int maxSize, const int printCensor, const char censorCharacter) {
    if (maxSize <= 0) return NULL;

    // Crea il buffer
    char* buffer = malloc((maxSize + 1) * sizeof(char));
    if (!buffer) return NULL;

    int index = 0;

#ifndef _WIN32
    flush_stdin_cp();
#endif

    while (1) {
        const int ch = get_pressed_key_cp();

#ifdef _WIN32
        if (ch == 13) break;     // Enter
#else
        if (ch == '\n') break;   // Enter su macOS/Linux
#endif

        // Backspace
        if (ch == 8 || ch == 127) {
            if (index > 0) {
                index--;
                if (printCensor == 1) {
                    printf("\b \b");
                    fflush(stdout);
                }
            }
        }
        // Carattere stampabile
        else if (ch >= 32 && ch <= 126) {
            if (index < maxSize) {
                buffer[index++] = (char)ch;

                if (printCensor == 1) {
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