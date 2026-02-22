//
// Created by Lorenzo on 22/02/2026.
//

#include <stdio.h>

#include "../../includes/menus.h"
#include "../../includes/accounts.h"
#include "../../includes/consolecolors.h"
#include "../../includes/data.h"
#include "../../includes/lists.h"
#include "../../includes/supremeio.h"

void print_account_line(UserAccount* account) {
    printf("- %s%5d %s- %s%s %s %s %s ~ %s%s\n%s", RED, account->id, RESET, BG_YELLOW, BLACK, account->name, account->surname, RESET, YELLOW, account->username, RESET);
}

void print_menu_adm() {
    // Pulisci lo schermo
    clear_screen_cp();

    // Intestazione
    print_program_head();

    // Scrivi la lista degli account con ID - Nome e Cognome - Username
    const ListNode* node = people_list->head;
    while (node != nullptr) {
        print_account_line(node->value);
        node = node->next;
    }
}

void launch_account_deletion_menu() {
    while (true) {
        // Stampa a schermo il menu
        print_menu_adm();

        if (people_list->size == 0) {
            printf("Non sono disponibili elementi! Premi un tasto per uscire...");
            get_pressed_key_cp();
            break;
        }

        // Seleziona account da eliminare
        int id = 0;
        printf("\nInserisci l'ID dell'account da eliminare o un numero negativo per uscire -> ");
        while (!scanf("%d", &id) || (!exists_account(id) && id >= 0)) { // NOLINT(*-err34-c)
            fflush(stdin);
            printf("ID non valido! Riprova -> ");
        }

        // Se l'ID è negativo
        if (id < 0) {
            break;
        }

        // Elimina l'account
        remove_account(id);
    }
}