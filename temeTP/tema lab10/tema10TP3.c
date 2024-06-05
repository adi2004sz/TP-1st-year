#include <stdio.h>

// Aplicația 10.3: Determinați recursiv cifra maximă a unui număr natural

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int cifra_max(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        return max(n % 10, cifra_max(n / 10));
    }
}

void p3(void)
{
    printf("%d\n", cifra_max(264368));
}

int main(void)
{
    p3();
    return 0;
}
