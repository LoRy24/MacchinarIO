//
// Created by Lorenzo on 22/02/2026.
//

#include <stdio.h>

#include "../../includes/menus.h"
#include "../../includes/accounts.h"
#include "../../includes/cypher.h"
#include "../../includes/data.h"
#include "../../includes/supremeio.h"

void print_account_card(UserAccount* account) {
    printf("|~------[ %d ]------~|\n", account->id);
    printf("- Username > %s\n", account->username);
    printf("- Name & Surname > %s %s\n", account->name, account->surname);
    printf("- Fiscal Code > %s\n", account->fiscal_code);
    printf("- Email > %s\n", account->email);
    printf("- Password (Hash) > %s\n", account->password);
    printf("- Password (Decifrata) > %s\n", decode_from_cesar(account->password));
    printf("|~------[ %d ]------~|\n\n", account->id);
}

void print_menu_alm() {
    // Pulisci lo schermo
    clear_screen_cp();

    // Intestazione
    print_program_head();

    // Vedi quanti accounts ci sono
    if (get_total_accounts() == 0) {
        printf("Non sono presenti account!\n\n");
    }
    else {
        const ListNode* node = people_list->head;
        while (node != NULL) {
            UserAccount* account = node->value;
            print_account_card(account);
            node = node->next;
        }
    }

    // Per tornare indietro
    printf("Premi un tasto per tornare indietro...\n");
}

void launch_accounts_list_menu() {
    print_menu_alm();
    get_pressed_key_cp();
}