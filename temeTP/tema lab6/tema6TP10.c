#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Aplicația 6.10: Să se scrie un program denumit criptare, care criptează/decriptează un text primit în linia de
// comandă. Programul va fi apelat în felul următor: ./criptare operatie cheie cuvant1 cuvant2 ...
// Operația poate fi enc pentru criptare sau dec decriptare. Cheia este un număr întreg. Algoritmul de criptare este
// următorul: pentru fiecare literă din cuvinte se consideră codul său ASCII, la care se adună cheia specificată,
// rezultând un nou cod ASCII, cel al literei criptate. Adunarea este circulară, adică ‘z’ incrementat cu 1 devine ‘a’.
// Decriptarea este inversă: din cuvintele criptate se scade circular cheia specificată. Literele mari se transformă la
// început în litere mici.
// Exemple:
// ./criptare enc 1 zaraza -> absbab
// ./criptare dec 1 bcfdfebs -> abecedar
// ./criptare enc 10 vine VINE primavara PRImaVAra -> fsxo fsxo zbswkfkbk zbswkfkbk

void encrypt(char *word, int key) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) {
            if (isupper(word[i])) {
                word[i] = ((word[i] - 'A' + key) % 26) + 'A';
            } else {
                word[i] = ((word[i] - 'a' + key) % 26) + 'a';
            }
        }
    }
}

void decrypt(char *word, int key) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (isalpha(word[i])) {
            if (isupper(word[i])) {
                word[i] = (((word[i] - 'A' - key) + 26) % 26) + 'A';
            } else {
                word[i] = (((word[i] - 'a' - key) + 26) % 26) + 'a';
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <enc/dec> <key> <word1> <word2> ...\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[2]);
    if (key < 0) {
        printf("Key must be a non-negative integer.\n");
        return 1;
    }

    for (int i = 3; i < argc; i++) {
        if (strcmp(argv[1], "enc") == 0) {
            encrypt(argv[i], key);
        } else if (strcmp(argv[1], "dec") == 0) {
            decrypt(argv[i], key);
        } else {
            printf("Invalid operation.\n");
            return 1;
        }
        printf("%s ", argv[i]);
    }
    printf("\n");

    return 0;
}
