//
// Created by Lorenzo Rocca on 21/02/26.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include "../includes/cypher.h"
#include "../includes/storage.h"

// Valori globali
char CYPHER_KEY = -1;

// Gestione delle chiavi di codifica

char generate_key() {
    srand(time(nullptr)); // NOLINT(*-msc51-cpp)
    return (char) (rand() % 255 + 1); // NOLINT(*-msc50-cpp)
}

void load_cypher() {
    // Creazione e controllo esistenza della cartella data
    fix_data_folder();

    // Vedi se esiste il file per la chiave
    FILE *key_file = fopen("data/key.meow", "r");
    if (key_file) {
        // Leggi la chiave che è un byte
        fread(&CYPHER_KEY, sizeof(char), 1, key_file);
        fclose(key_file);
    }
    else {
        // Scriviamo la chiave nel file
        key_file = fopen("data/key.meow", "w");

        // Genera la chiave e salva
        const char key = generate_key();
        CYPHER_KEY = key;
        fwrite(&key, sizeof(char), 1, key_file);

        fclose(key_file);
    }
}

// Funzioni di codifica

char* encode_with_cesar(const char* decoded) {
    // Codifica
    char* encoded = malloc(sizeof(char) * (strlen(decoded) + 1));
    for (int i = 0; i < strlen(decoded); i++) {
        encoded[i] = (char)(((int) decoded[i] + (int) CYPHER_KEY) % 256);
    }
    encoded[strlen(decoded)] = '\0';

    return encoded;
}

char* decode_from_cesar(const char* encoded) {
    // Decodifica
    char* decoded = malloc(sizeof(char) * (strlen(encoded) + 1));
    for (int i = 0; i < strlen(encoded); i++) {
        decoded[i] = (char)(((int) encoded[i] - (int) CYPHER_KEY) % 256);
    }
    decoded[strlen(encoded)] = '\0';

    return decoded;
}
