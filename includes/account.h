//
// Created by Lorenzo Rocca on 19/02/26.
//

#ifndef MACCHINARIO_ACCOUNT_H
#define MACCHINARIO_ACCOUNT_H

typedef struct account_s {
    int id;
    char username[17];
    char name[65];
    char surname[65];
    char email[129];
    char password[257];
} UserAccount;

#endif //MACCHINARIO_ACCOUNT_H