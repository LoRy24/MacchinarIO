//
// Created by Lorenzo Rocca on 21/02/26.
//

#ifndef MACCHINARIO_DATA_H
#define MACCHINARIO_DATA_H

#include "accounts.h"
#include "lists.h"

extern List* people_list;
extern int id_counter;

void load_data();
bool save_data();
void add_account(UserAccount* account);
void remove_account(int id);
int get_total_accounts();
int generate_id();
bool exists_account(int id);

#endif //MACCHINARIO_DATA_H