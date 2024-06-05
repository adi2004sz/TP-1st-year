#include <stdio.h>

// Problema 11.5 Divide et Impera

void afisareLiterara(int n)
{
    if (n < 0 || n >= 1000)
    {
        printf("Numarul trebuie sa fie intre 0 si 999.\n");
        return;
    }

    const char *unitati[] = {"zero", "unu", "doi", "trei", "patru", "cinci", "sase", "sapte", "opt", "noua"};
    const char *zeci[] = {"", "zece", "douazeci", "treizeci", "patruzeci", "cincizeci", "saizeci", "saptezeci", "optzeci", "nouazeci"};
    const char *sute[] = {"", "o suta", "doua sute", "trei sute", "patru sute", "cinci sute", "sase sute", "sapte sute", "opt sute", "noua sute"};

    int suta = n / 100;
    int zecile = (n / 10) % 10;
    int unitatea = n % 10;

    printf("%s", sute[suta]);

    if (suta == 0 && zecile == 0 && unitatea == 0)
    {
        printf(" zero");
    }
    else if (zecile == 1)
    {
        if (unitatea == 0)
        {
            printf(" zece");
        }
        else if (unitatea == 1)
        {
            printf(" unsprezece");
        }
        else if (unitatea == 2)
        {
            printf(" doisprezece");
        }
        else if (unitatea == 3)
        {
            printf(" treisprezece");
        }
        else if (unitatea == 4)
        {
            printf(" paisprezece");
        }
        else if (unitatea == 5)
        {
            printf(" cincisprezece");
        }
        else if (unitatea == 6)
        {
            printf(" saisprezece");
        }
        else if (unitatea == 7)
        {
            printf(" saptesprezece");
        }
        else if (unitatea == 8)
        {
            printf(" optsprezece");
        }
        else if (unitatea == 9)
        {
            printf(" nouasprezece");
        }
    }
    else
    {
        printf(" %s", zeci[zecile]);
        if (unitatea != 0)
        {
            printf(" %s", unitati[unitatea]);
        }
    }

    printf("\n");
}

void p5(void)
{
    int n;
    while (1)
    {
        printf("Introduceti un numar (0-999): ");
        scanf("%d", &n);
        if (n == 1000)
        {
            break;
        }
        afisareLiterara(n);
    }
}

int main(void)
{
    p5();
    return 0;
}
