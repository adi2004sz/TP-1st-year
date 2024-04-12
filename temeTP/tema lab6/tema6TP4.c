#include <stdio.h>
#include <stdarg.h>

// Aplicația 6.4: Să se scrie o funcție crescator(int n,char tip,...) care primește un număr n de valori și returnează 1
// dacă ele sunt în ordine strict crescătoare, altfel 0. Caracterul tip indică tipul valorilor și poate fi ‘d’ - int, ‘f’ - double.
// Exemplu: printf(“%d”,crescator(3,’d’,-1,7,9));


int crescator(int n, char tip, ...) {
    va_list args;
    va_start(args, tip);

    if (tip == 'd') {
        int prev = va_arg(args, int);
        for (int i = 1; i < n; ++i) {
            int current = va_arg(args, int);
            if (current <= prev) {
                va_end(args);
                return 0;
            }
            prev = current;
        }
    } else if (tip == 'f') {
        double prev = va_arg(args, double);
        for (int i = 1; i < n; ++i) {
            double current = va_arg(args, double);
            if (current <= prev) {
                va_end(args);
                return 0;
            }
            prev = current;
        }
    }

    va_end(args);
    return 1;
}

int main() {
    printf("%d\n", crescator(3, 'd', -1, 7, 9)); //numere întregi
    printf("%d\n", crescator(3, 'f', 1.5, 3.7, 9.1)); //numere reale
    return 0;
}
