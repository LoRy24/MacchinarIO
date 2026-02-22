# 📌 MacchinarIO

Programma in C per la gestione di utenti e password con cifratura stile "Cesare" (deprecata nel 2012 a.C., ma ancora didatticamente affascinante 😄).

Progetto realizzato a scopo educativo (BIG 2026) per esercitarsi con gestione file, stringhe e modularizzazione in C.

## 🧠 Descrizione

**MacchinarIO** è un'applicazione CLI scritta in C che permette di:

- Registrare utenti
- Effettuare login con username e password
- Salvare le credenziali su file
- Applicare una cifratura semplice (shift tipo Cesare)

⚠️ Nota: la cifratura utilizzata NON è sicura per uso reale. È presente solo per scopi didattici.

## ✨ Funzionalità

- ✅ Registrazione utente
- ✅ Login con verifica credenziali
- ✅ Cifratura e decifratura password
- ✅ Persistenza dati su file
- ✅ Struttura modulare con header e file separati

## 📁 Struttura del progetto
```
MacchinarIO/
│
├── includes/ # Header files (.h)
├── src/ # File sorgente (.c)
├── CMakeLists.txt # Configurazione CMake
├── .gitignore
├── LICENSE
├── ...
└── README.md
```

## 🛠️ Requisiti

- GCC (o compilatore C compatibile)
- CMake
- Sistema operativo Linux / macOS / Windows (con toolchain C)

## 🚀 Compilazione

Clona il repository:

```bash
git clone https://github.com/LoRy24/MacchinarIO.git
cd MacchinarIO
```

Crea la directory di build e compila:

```bash
mkdir build
cd build
cmake ..
make
```

Verrà generato l'eseguibile nella cartella build/.

## ▶️ Esecuzione

Da dentro la cartella build:
```bash
./MacchinarIO
```

Segui le istruzioni a schermo per:
- Registrare un nuovo utente
- Effettuare il login
- Gestire le credenziali

## 🧩 Dettagli tecnici

Il progetto copre:
- Manipolazione di stringhe in C
- Lettura e scrittura su file
- Algoritmi di cifratura base
- Modularizzazione del codice
- Uso di CMake per la build automation

## 🔐 Sicurezza

La cifratura implementata è una semplice variante del cifrario di Cesare. Non utilizzare questo sistema in ambienti reali o per la gestione di password sensibili.

Per sistemi reali si raccomandano:
- Hashing con SHA-256 o superiore
- Salting delle password
- Librerie crittografiche certificate

## 🤝 Contribuire
1. Fai un fork del progetto
2. Crea una branch (feature/nome-feature)
3. Effettua le modifiche
4. Apri una Pull Request

## 📜 Licenza
Vedi il file apposito

📚 Obiettivo del progetto

Scopo didattico:
- Comprendere meglio la gestione della memoria
- Lavorare con file system
- Strutturare un piccolo progetto C reale
