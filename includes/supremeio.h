//
// Created by Lorenzo Rocca on 19/02/26.
//

#ifndef MACCHINARIO_SUPREMEIO_H
#define MACCHINARIO_SUPREMEIO_H

// Specifico per input

#ifdef _WIN32
    #include <conio.h>
#elif
    #include <termios.h>
    #include <unistd.h>
#endif

// Funzioni

int get_pressed_key_cp();
void clear_screen_cp();
char* input_password_cp(int maxSize, bool printCensor, char censorCharacter);

#endif //MACCHINARIO_SUPREMEIO_H