//
// Created by Lorenzo on 21/02/2026.
//

#include "../includes/lists.h"

// Funzioni di gestione dei nodi

ListNode* create_list_node(void* value) {
    ListNode* node = malloc(sizeof(ListNode));
    node->value = value;
    node->next = nullptr;
    return node;
}

void destroy_list_node(ListNode* node) {
    free(node);
}

// Funzione per la gestione della lista

List create_list() {
    List list;
    list.size = 0;
    list.head = nullptr;
    return list;
}

void clear_list(List *list) {
    ListNode* node = list->head;
    while (node != nullptr) {
        ListNode* sel = node;
        node = node->next;
        destroy_list_node(sel);
    }

    list->size = 0;
}

void destroy_list(List *list) {
    // Elimina gli elementi della lista
    clear_list(list);

    // Pulisci la memoria
    free(list);
}

void append_list(List *list, void* value) {
    // Crea il nodo
    ListNode* node = create_list_node(value);

    // Vedi dove metterlo nella lista
    if (list->head == nullptr) {
        list->head = node;
    }
    else {
        ListNode* tail = list->head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = node;
    }
}