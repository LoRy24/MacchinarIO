//
// Created by Lorenzo Rocca on 19/02/26.
//

#include <stdio.h>

#include "../includes/consolecolors.h"
#include "../includes/supremeio.h"
#include "../includes/cypher.h"
#include "../includes/menus.h"

// CONSEGNA:
// 1) Inserimento delle informazioni
// OK 2) Scelta della struttura dati
// OK 3) Crittografia delle password con cesare
// 4) Registrazione
// 5) Check della validità dei dati inseriti

void exit_routine();

int main(void) {
    // Carica gli elementi per la cifratura
    load_cypher();

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