//
// Created by Lorenzo on 22/02/2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../includes/accounts.h"
#include "../../includes/cypher.h"
#include "../../includes/data.h"
#include "../../includes/menus.h"
#include "../../includes/supremeio.h"

void print_menu_arm() {
    // Pulisci lo schermo
    clear_screen_cp();

    // Intestazione
    print_program_head();

    // Informativa
    printf("Stai creando un nuovo account all'interno del sistema.\nInserisci tutti i dati richiesti, grazie!\n\n");
}

void launch_account_registration_menu() {
    // Scrivi i dati del menu
    print_menu_arm();

    // Prepara l'oggetto per l'account
    UserAccount* account = malloc(sizeof(UserAccount));

    // Chiedi un username
    printf("Inserisci l'username -> ");
    scanf("%s", account->username);
    fflush(stdin);

    // Chiedi il nome
    printf("Inserisci il nome -> ");
    scanf("%s", account->name);
    fflush(stdin);

    // Chiedi il cognome
    printf("Inserisci il cognome -> ");
    scanf("%s", account->surname);
    fflush(stdin);

    // Chiedi il codice fiscale
    while (strlen(account->fiscal_code) != 16) {
        printf("Inserisci il codice fiscale -> ");
        scanf("%s", account->fiscal_code);
        fflush(stdin);

        if (strlen(account->fiscal_code) != 16) {
            printf("Codice fiscale non valido!\n");
        }
    }

    // Chiedi una email
    printf("Inserisci l'email -> ");
    scanf("%s", account->email);
    fflush(stdin);

    // Chiedi la password
    printf("Inserisci la password -> ");
    char* password = input_password_cp(128, true, '*');
    sprintf(account->password, "%s", encode_with_cesar(password));
    free(password);
    fflush(stdin);

    // Chiedi la conferma
    printf("Premi Y per confermare la creazione dell'account, un altro per abortire\n");
    const int key = get_pressed_key_cp();
    if (key == 'y') {
        // Aggiungilo ai dati (lo salva automaticamente)
        add_account(account);
    }
    else {
        free(account);
        printf("\nCreazione dell'account abortita!\nPremere un tasto per continuare...\n");
        get_pressed_key_cp();
    }
}