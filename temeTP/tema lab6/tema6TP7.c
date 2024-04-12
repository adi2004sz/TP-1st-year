#include <stdio.h>
#include <stdarg.h>

// Aplicația 6.7: Să se scrie o funcție int comune(int nVec,...) care primește un număr de vectori cu valori de tip int și
// vectorii propriu-ziși. Fiecare vector se dă prin 2 argumente: un pointer la elementele sale și dimensiunea. Funcția
// va returna numărul de elemente comune care se regăsesc în toți vectorii.
// Exemplu: comune(3,v1,2,v2,3,v3,3) => returnează 2 pentru v1={5,8}, v2={8,3,5}, v3={5,0,8}

int comune(int nVec, ...) {
    va_list args;
    va_start(args, nVec);

    int *vec = va_arg(args, int *);
    int size = va_arg(args, int);

    int count = 0;
    for (int i = 0; i < size; ++i) {
        int current = vec[i];
        int found_in_all = 1;
        for (int j = 1; j < nVec; ++j) {
            int *curr_vec = va_arg(args, int *);
            int curr_size = va_arg(args, int);
            int found = 0;
            for (int k = 0; k < curr_size; ++k) {
                if (current == curr_vec[k]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                found_in_all = 0;
                break;
            }
        }
        if (found_in_all) {
            ++count;
        }
    }

    va_end(args);
    return count;
}

int main() {
    int v1[] = {5, 8};
    int v2[] = {8, 3, 5};
    int v3[] = {5, 0, 8};
    printf("%d\n", comune(3, v1, 2, v2, 3, v3, 3));
    return 0;
}
