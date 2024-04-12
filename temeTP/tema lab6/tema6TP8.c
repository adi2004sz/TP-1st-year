#include <stdio.h>
#include <stdarg.h>

// Aplicația 6.8: Să se scrie o funcție sortare(int n,...) care pe prima poziție are numărul de elemente de sortat, iar
// pe următoarele poziții n adrese de valori de tip int. Funcția va sorta crescător valorile de la adresele date.
// Exemplu: sortare(3,&i,&j,&k); // sortează crescător valorile lui i, j și k


void sortare(int n, ...) {
    va_list args;
    va_start(args, n);

    int *ptr = va_arg(args, int *);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int *curr_ptr = va_arg(args, int *);
            if (*ptr > *curr_ptr) {
                int temp = *ptr;
                *ptr = *curr_ptr;
                *curr_ptr = temp;
            }
            ptr = curr_ptr;
        }
    }

    va_end(args);
}

int main() {
    int i = 5, j = 3, k = 7;
    sortare(3, &i, &j, &k);
    printf("i = %d, j = %d, k = %d\n", i, j, k);
    return 0;
}
