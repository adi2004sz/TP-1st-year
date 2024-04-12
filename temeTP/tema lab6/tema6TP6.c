#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

// Aplicația 6.6: Să se scrie o funcție char *concat(int n,...) care primește un număr de șiruri de caractere și apoi
// șirurile propriu-zise. Funcția va concatena într-un nou șir, alocat dinamic, conținuturile tuturor șirurilor date, cu câte
// un spațiu între ele și va returna acest șir.
// Exemplu: concat(3,”Ion”,”si”,”Ana”) => “Ion si Ana”

char *concat(int n, ...) {
    va_list args;
    va_start(args, n);

    size_t total_len = 0;
    for (int i = 0; i < n; ++i) {
        total_len += strlen(va_arg(args, const char *));
    }
    va_end(args);

    char *result = (char *)malloc(total_len + n); // Se adaugă n - 1 spații între șiruri
    if (!result) {
        fprintf(stderr, "Alocare esuata.\n");
        exit(EXIT_FAILURE);
    }

    va_start(args, n);
    strcpy(result, va_arg(args, const char *));
    for (int i = 1; i < n; ++i) {
        strcat(result, " ");
        strcat(result, va_arg(args, const char *));
    }
    va_end(args);

    return result;
}

int main() {
    char *concatenated = concat(3, "Ion", "si", "Ana");
    printf("%s\n", concatenated);
    free(concatenated);
    return 0;
}
