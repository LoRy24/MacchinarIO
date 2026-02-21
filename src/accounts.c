//
// Created by Lorenzo on 21/02/2026.
//

#include <stdio.h>
#include <stdlib.h>

#include "../includes/cypher.h"
#include "../includes/accounts.h"

inline UserAccount* create_account(const int id, char* username, char* name, char* surname, char* fiscal_code, char* email, const char* password) {
    UserAccount* account = malloc(sizeof(UserAccount));

    // Assegna tutti i dati normali
    account->id = id;
    sprintf(account->username, "%16s", username);
    sprintf(account->name, "%64s", name);
    sprintf(account->surname, "%64s", surname);
    sprintf(account->fiscal_code, "%16s", fiscal_code);
    sprintf(account->email, "%128s", email);

    // Cifra la password
    sprintf(account->password, "%128s", encode_with_cesar(password));

    return account;
}