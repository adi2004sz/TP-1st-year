#include <stdio.h>

// Aplicația 10.7: Serii de puteri. Calculaţi, cu o precizie dată, valoarea lui ex după dezvoltarea în serie Taylor:
// ex = 1 + x1
// /1! + x2
// /2! + x3
// /3! + ...
// Calculaţi suma până când termenul curent devine mai mic decât o valoare dată (de ex. 10-6
// ). Pentru a evita
// recalcularea lui n! transmiteţi ca parametru şi termenul curent, şi calculaţi-l pe următorul după relaţia: xn
// /n! = xn1
// /(n-1)! * x/n.

float serieTaylor(float *valoare, float *termenAnterior, int *n, int x, float precizie)
{
    if (*termenAnterior < precizie)
    {
        return *valoare;
    }
    else
    {
        *n = *n + 1;
        *termenAnterior = *termenAnterior * x / *n;
        *valoare = *valoare + *termenAnterior;
        return serieTaylor(valoare, termenAnterior, n, x, precizie);
    }
}

void p7(void)
{
    float valoare = 1;
    float termenAnterior = 1;
    int n = 0;
    int x = 1;
    float precizie = 0.000001;
    printf("%f\n", serieTaylor(&valoare, &termenAnterior, &n, x, precizie));
}

int main(void)
{
    p7();
    return 0;
}
