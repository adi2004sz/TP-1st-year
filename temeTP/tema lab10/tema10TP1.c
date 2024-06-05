#include <stdio.h>

// Aplicația 10.1: Calculați recursiv cel mai mare divizor comun a două numere

int cmmdc(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return cmmdc(b, a % b);
    }
}

void p1(void)
{
    printf("%d\n", cmmdc(24, 8));
}

int main(void)
{
    p1();
    return 0;
}
