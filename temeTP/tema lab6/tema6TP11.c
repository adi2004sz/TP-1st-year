#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aplicația 6.11: Un program primește în linia de comandă o expresie formată din numere reale și operatorii {addadunare, sub-scădere, mul-înmulțire, div-împărțire}. Programul va calcula valoarea expresiei și va afișa rezultatul.
// Expresia se calculează de la stânga la dreapta, fără a ține cont de precedența matematică a operatorilor.
// Exemplu: ./calcul 10.5 add 1.5 div 3 va afișa: 4

double calculate(double x, double y, char *op) {
    if (strcmp(op, "add") == 0) {
        return x + y;
    } else if (strcmp(op, "sub") == 0) {
        return x - y;
    } else if (strcmp(op, "mul") == 0) {
        return x * y;
    } else if (strcmp(op, "div") == 0) {
        return x / y;
    } else {
        printf("Invalid operator.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4 || argc % 2 == 0) {
        printf("Usage: %s <number> <operation> <number> ...\n", argv[0]);
        return 1;
    }

    double result = atof(argv[1]);
    for (int i = 2; i < argc - 1; i += 2) {
        result = calculate(result, atof(argv[i + 1]), argv[i]);
    }

    printf("%.2f\n", result);
    return 0;
}
