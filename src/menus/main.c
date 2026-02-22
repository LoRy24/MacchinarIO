//
// Created by Lorenzo on 21/02/2026.
//

#include <stdio.h>

#include "../../includes/menus.h"
#include "../../includes/supremeio.h"

void print_menu_mm() {
    // Pulisci lo schermo
    clear_screen_cp();

    // Intestazione
    print_program_head();

    printf("V. Visualizza accounts\n");
    printf("R. Registra account\n");
    printf("E. Elimina account\n\n");
    printf("Q. Esci\n");
}

void launch_main_menu() {
    int input = '\0';
    while (input != 'q') {
        print_menu_mm();

        input = get_pressed_key_cp();

        switch (input) {
            case 'v': {
                launch_accounts_list_menu();
                break;
            }

            case 'r': {
                launch_account_registration_menu();
                break;
            }

            case 'e': {
                launch_account_deletion_menu();
                break;
            }

            default: {
                break;
            }
        }
    }
}