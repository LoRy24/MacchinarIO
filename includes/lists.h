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

inline ListNode* create_list_node(void* value) {
    ListNode* node = malloc(sizeof(ListNode));
    node->value = value;
    node->next = nullptr;
    return node;
}

inline void destroy_list_node(ListNode* node) {
    free(node);
}

// Funzione per la gestione della lista

inline List create_list() {
    List list;
    list.size = 0;
    list.head = nullptr;
    return list;
}

#endif //MACCHINARIO_LISTS_H