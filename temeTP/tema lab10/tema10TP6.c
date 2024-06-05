#include <stdio.h>

// Aplicația 10.6: Se poate demonstra (v. Knuth) ca limita raportului a doi termeni invers consecutivi din sirul lui
// Fibbonaci este egala cu Phi (proportia de aur). 

int fib(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

double phi(int n)
{
    if (n <= 1)
    {
        return 1.0;
    }
    else
    {
        double fib_n = fib(n);
        double fib_n_minus_1 = fib(n - 1);
        return fib_n / fib_n_minus_1;
    }
}

void p6(void)
{
    printf("%f\n", phi(20));
}

int main(void)
{
    p6();
    return 0;
}
