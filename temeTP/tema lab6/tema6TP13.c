#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Aplicația 6.13: Un program primește în linia de comandă ca prim argument un cod de operație și pe urmă o serie
// de cuvinte. Codul poate fi: 0-afișează numărul total de litere din toate cuvintele: 1-afișează fiecare literă de câte ori
// apare în toate cuvintele.
// Exemplu: ./statistica 0 ion merge la film va afișa: 14

void calculate_statistics(int code, int argc, char *argv[]) {
    int total_letters = 0;
    int frequency[26] = {0};

    for (int i = 2; i < argc; i++) {
        int len = strlen(argv[i]);
        total_letters += len;

        for (int j = 0; j < len; j++) {
            char c = tolower(argv[i][j]);
            if (isalpha(c)) {
                frequency[c - 'a']++;
            }
        }
    }

    if (code == 0) {
        printf("Total letters: %d\n", total_letters);
    } else if (code == 1) {
        for (int i = 0; i < 26; i++) {
            if (frequency[i] > 0) {
                printf("%c: %d\n", 'a' + i, frequency[i]);
            }
        }
    } else {
        printf("Invalid code.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <code> <word1> <word2> ...\n", argv[0]);
        return 1;
    }

    int code = atoi(argv[1]);
    calculate_statistics(code, argc, argv);

    return 0;
}