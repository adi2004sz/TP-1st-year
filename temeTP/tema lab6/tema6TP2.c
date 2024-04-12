#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Aplicația 6.2: Să se scrie o funcție float *allocVec(int n,...) care primește pe prima poziție un număr de elemente
// iar apoi n elemente reale. Funcția va aloca dinamic un vector de tip float în care va depune toate elementele.
// Exemplu: allocVec(3,7.2,-1,0) => {7.2, -1, 0}

float *allocVec(int n, ...) {
    float *vec = (float *)malloc(n * sizeof(float));
    if (!vec) {
        fprintf(stderr, "Alocare esuata.\n");
        exit(EXIT_FAILURE);
    }

    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; ++i) {
        vec[i] = va_arg(args, double); // Se folosește double pentru că float este promovat automat la double în variadic functions
    }
    va_end(args);

    return vec;
}

int main() {
    float *vec = allocVec(3, 7.2, -1, 0);
    for (int i = 0; i < 3; ++i) {
        printf("%.2f ", vec[i]);
    }
    free(vec);
    return 0;
}
