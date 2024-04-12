#include <stdio.h>
#include <stdlib.h>

// Aplicația 6.9: Scrieți un program care calculează suma parametrilor primiți din linia de comandă (numere reale).
// Exemplu: execuția fără parametri va fișa 0, iar execuția cu parametrii 1.1 6.57 99.122 va afișa 106.792

int main(int argc, char *argv[]) {
    double sum = 0.0;
    for (int i = 1; i < argc; i++) {
        sum += atof(argv[i]);
    }
    printf("%.3f\n", sum);
    return 0;
}
