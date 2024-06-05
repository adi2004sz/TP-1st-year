#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Aplicația 10.5: Se considera sirul-de-caractere de tip Fibbonaci in care primii doi termeni sunt sirurile de caractere
// s1 si s2 (pot fi transmise ca si parametri functiei), iar orice alt termen se obtine prin concatenarea celor doi termeni
// anteriori. Sa se implementeze o functie care un numar natural n (si orice alti parametri considerati necesari) si
// afiseaza termenul de pe pozitia n din sirul construit conform celor de mai sus.

char *strFib(int n, char *s1, char *s2)
{
    if (n == 1)
    {
        return s1;
    }
    else if (n == 2)
    {
        return s2;
    }
    else
    {
        char *result = (char *)malloc(strlen(s1) + strlen(s2) + 1);
        strcpy(result, s1);
        strcat(result, s2);
        char *nextFib = strFib(n - 1, s2, result);
        free(result);
        return nextFib;
    }
}

void p5(void)
{
    char *s1 = "a";
    char *s2 = "b";
    char *result = strFib(10, s1, s2);
    printf("%s\n", result);
    free(result);
}

int main(void)
{
    p5();
    return 0;
}
