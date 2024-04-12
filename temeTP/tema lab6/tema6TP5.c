#include <stdio.h>
#include <stdarg.h>

// Aplicația 6.5: Să se implementeze o funcție input(const char *fmt,...). În șirul fmt pot fi caractere obișnuite (orice
// în afară de %) și placeholdere (% urmat de o literă). Pentru fiecare placeholder posibil ( %d - int, %f -float, %c -
// char ), în lista de argumente variabile se va afla adresa unei variabile de tipul corespunzător. Funcția afișează pe
// ecran caracterele obișnuite și citește de la tastatură pentru placeholdere.
// Exemplu: input(”n=%dch=%c”,&n,&ch); // citește o valoare de tip int în n și de tip char în ch


void input(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    while (*fmt) {
        if (*fmt == '%') {
            switch (*(++fmt)) {
                case 'd':
                    scanf("%d", va_arg(args, int *));
                    break;
                case 'f':
                    scanf("%f", va_arg(args, float *));
                    break;
                case 'c':
                    scanf(" %c", va_arg(args, char *));
                    break;
            }
        } else {
            putchar(*fmt);
        }
        ++fmt;
    }

    va_end(args);
}

int main() {
    int n;
    char ch;
    input("n=%dch=%c", &n, &ch);
    printf("n = %d, ch = %c\n", n, ch);
    return 0;
}
