//
// Created by Lorenzo Rocca on 21/02/26.
//

#include "../includes/data.h"

#include <stdio.h>
#include <stdlib.h>

#include "../includes/accounts.h"
#include "../includes/lists.h"
#include "../includes/storage.h"

List* people_list;
int id_counter;

void load_data() {
    // Inizializza la lista
    people_list = create_list();

    // Cartella dati
    fix_data_folder();

    // Vedi se esiste il file dei dati
    FILE* data_file = fopen("data/data.meow", "r");
    if (data_file) {
        // Leggi l'ultimo ID
        fread(&id_counter, sizeof(int), 1, data_file);
        printf("%d", id_counter);

        // Leggi la dimensione della lista salvata
        int items;
        fread(&items, sizeof(int), 1, data_file);
        printf("%d", items);

        // Leggi ogni elemento e mettilo nella lista
        for (int i = 0; i < items; ++i) {
            UserAccount* account = malloc(sizeof(UserAccount));
            fread(account, sizeof(UserAccount), 1, data_file);
            append_list(people_list, account);
        }
    }
    else {
        save_data();
    }
}

bool save_data() {
    FILE* data_file = fopen("data/data.meow", "w");
    if (data_file) {
        // Scrivi l'ultimo ID generato
        fwrite(&id_counter, sizeof(int), 1, data_file);

        // Scrivi la dimensione della lista
        fwrite(&people_list->size, sizeof(int), 1, data_file);

        // Scrivi ogni elemento della lista
        const ListNode* node = people_list->head;
        while (node != nullptr) {
            const UserAccount* account = node->value;
            fwrite(account, sizeof(UserAccount), 1, data_file);
            node = node->next;
        }

        fclose(data_file);
        return true;
    }

    return false;
}

void add_account(UserAccount* account) {
    account->id = generate_id();
    id_counter++;
    append_list(people_list, account);
    save_data();
}

void remove_account(const int id) {
    remove_from_list_by_account_id(people_list, id);
    save_data();
}

int get_total_accounts() {
    return people_list->size;
}

int generate_id() {
    return id_counter;
}

bool exists_account(const int id) {
    const ListNode* node = people_list->head;
    while (node != nullptr) {
        if (((UserAccount*)(node->value))->id == id) return true;
        node = node->next;
    }
    return false;
}
