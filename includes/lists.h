//
// Created by Lorenzo Rocca on 21/02/26.
//

#ifndef MACCHINARIO_LISTS_H
#define MACCHINARIO_LISTS_H

#include <stdlib.h>

// Strutture

typedef struct list_node_s {
    void* value;
    struct list_node_s* next;
} ListNode;

typedef struct list_s {
    int size;
    ListNode* head;
} List;

// Funzioni di gestione dei nodi

ListNode* create_list_node(void* value);
void destroy_list_node(ListNode* node);

// Funzione per la gestione della lista

List* create_list();
void clear_list(List* list);
void destroy_list(List* list);
void append_list(List* list, void* value);

// Gestione specifica per liste di Account

void remove_from_list_by_account_id(List* list, int id);

#endif //MACCHINARIO_LISTS_H
