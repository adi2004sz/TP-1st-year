#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Aplicația 6.12: Un program primește în linia de comandă o serie de opțiuni și de cuvinte, mixate între ele. Opțiunile
// specifică operații care se execută asupra cuvintelor. Opțiunile încep cu - (minus) și pot fi: u-transformă toate literele
// cuvintelor în majuscule; f-transformă prima literă în majusculă și următoarele în minuscule; r-inversează literele din
// cuvinte. După fiecare cuvânt se resetează toate opțiunile anterioare. Să se afișeze cuvintele primite în linia de
// comandă cu transformările aplicate.
// Exemplu: ./procesare -f mAria -r -u abac va afișa: Maria CABA

void process_word(char *word, char *options) {
    while (*options) {
        switch (*options) {
            case 'u':
                for (int i = 0; word[i] != '\0'; i++) {
                    word[i] = toupper(word[i]);
                }
                break;
            case 'f':
                word[0] = toupper(word[0]);
                for (int i = 1; word[i] != '\0'; i++) {
                    word[i] = tolower(word[i]);
                }
                break;
            case 'r':
                {
                    int len = strlen(word);
                    for (int i = 0; i < len / 2; i++) {
                        char temp = word[i];
                        word[i] = word[len - i - 1];
                        word[len - i - 1] = temp;
                    }
                }
                break;
        }
        options++;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <-u/-f/-r> <word1> <word2> ...\n", argv[0]);
        return 1;
    }

    char *options = argv[1];
    for (int i = 2; i < argc; i++) {
        char *word = argv[i];
        process_word(word, options);
        printf("%s ", word);
    }
    printf("\n");

    return 0;
}
