#include <stdio.h>
#include <math.h>
#include <stdarg.h>

// Aplicația 6.3: Să se scrie o funcție absN(int n,...) care primește un număr n de adrese de tip float și setează la
// fiecare dintre aceste adrese valoarea absolută de la acea locație.
// Exemplu: absN(2,&x,&y); // echivalent cu x=fabs(x); y=fabs(y)

void absN(int n, ...) {
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; ++i) {
        float *ptr = va_arg(args, float *);
        *ptr = fabs(*ptr);
    }
    va_end(args);
}

int main() {
    float x = -5.5, y = 6.7;
    absN(2, &x, &y);
    printf("x = %.2f, y = %.2f\n", x, y);
    return 0;
}
