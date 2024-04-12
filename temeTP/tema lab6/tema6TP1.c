#include <stdio.h>
#include <stdarg.h>

// Aplicația 6.1: Să se modifice exemplul 2 astfel încât funcția err să încapsuleze și condiția de eroare. Pentru
// aceasta, ea primește în plus pe prima poziție o variabilă de tip int care reprezintă o valoare logică. Dacă valoarea
// este true, se va executa err ca în exemplu, altfel err nu va avea niciun efect.
// Exemplu de folosire: err(n<=0||n>100,"n invalid: %d\n",n); // fără if în față, deoarece err încapsulează condiția


void err(int condition, const char *fmt, ...) {
    if (condition) {
        va_list args;
        va_start(args, fmt);
        vfprintf(stderr, fmt, args);
        va_end(args);
    }
}

int main() {
    int n = 105;
    err(n <= 0 || n > 100, "n invalid: %d\n", n);
    return 0;
}
