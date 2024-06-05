#include <stdio.h>

// Aplicația 10.2: Calculați recursiv suma cifrelor unui număr natural.

int suma_cifrelor(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        return n % 10 + suma_cifrelor(n / 10);
    }
}

void p2(void)
{
    printf("%d\n", suma_cifrelor(123));
}

int main(void)
{
    p2();
    return 0;
}
