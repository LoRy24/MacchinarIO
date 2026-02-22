//
// Created by Lorenzo Rocca on 19/02/26.
//

#include <stdio.h>

#include "../includes/consolecolors.h"
#include "../includes/supremeio.h"
#include "../includes/cypher.h"
#include "../includes/data.h"
#include "../includes/menus.h"

void exit_routine();

int main(void) {
    // Carica gli elementi per la cifratura
    load_cypher();

    // Carica i dati del programma
    load_data();

    // Avvia menu principale
    launch_main_menu();

    // Attesa prima di uscire
    exit_routine();

    // Tutto OK
    return 0;
}

void exit_routine() {
    clear_screen_cp();
    print_program_head();
    printf("    |\\__/,|   (`\\\n");
    printf("  _.|o o  |_   ) )\n");
    printf("-(((---(((--------\n");
    printf("\nPremi un tasto per %suscire\n", BRIGHT_RED);
    get_pressed_key_cp();
}