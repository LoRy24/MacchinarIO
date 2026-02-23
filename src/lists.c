//
// Created by Lorenzo on 21/02/2026.
//

#include "../includes/lists.h"

#include <stdlib.h>

#include "../includes/accounts.h"

// Funzioni di gestione dei nodi

ListNode* create_list_node(void* value) {
    ListNode* node = malloc(sizeof(ListNode));
    node->value = value;
    node->next = NULL;
    return node;
}

void destroy_list_node(ListNode* node) {
    free(node);
}

// Funzione per la gestione della lista

List* create_list() {
    List* list = malloc(sizeof(List));
    list->size = 0;
    list->head = NULL;
    return list;
}

void clear_list(List* list) {
    ListNode* node = list->head;
    while (node != NULL) {
        ListNode* sel = node;
        node = node->next;
        destroy_list_node(sel);
    }

    list->size = 0;
}

void destroy_list(List* list) {
    // Elimina gli elementi della lista
    clear_list(list);

    // Pulisci la memoria
    free(list);
}

void append_list(List* list, void* value) {
    // Crea il nodo
    ListNode* node = create_list_node(value);

    // Vedi dove metterlo nella lista
    if (list->head == NULL) {
        list->head = node;
    }
    else {
        ListNode* tail = list->head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = node;
    }

    // Aggiungi l'elemento
    list->size++;
}

// Specifica per liste di account

void remove_from_list_by_account_id(List* list, const int id) {
    if (((UserAccount*) list->head->value)->id == id) {
        ListNode* node = list->head;
        list->head = list->head->next;
        destroy_list_node(node);
        list->size--;
    }
    else {
        ListNode* node = list->head;
        while (node->next != NULL) {
            if (((UserAccount*) node->next)->id == id) {
                node->next = node->next->next;
                destroy_list_node(node->next);
                list->size--;
                break;
            }
        }
    }
}
