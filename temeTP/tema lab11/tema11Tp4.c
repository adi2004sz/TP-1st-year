#include <stdio.h>
#include <stdlib.h>

// Problema 11.4 Greedy

typedef struct
{
    char nume[15];
    int valoare;
} Jucator;

int comparareJucatori(const void *a, const void *b)
{
    Jucator *jucator1 = (Jucator *)a;
    Jucator *jucator2 = (Jucator *)b;
    return jucator1->valoare - jucator2->valoare;
}

void p4(void)
{
    int n, m, i, count = 0;
    Jucator jucatori[100];
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%s %d", jucatori[i].nume, &jucatori[i].valoare);
    }

    qsort(jucatori, n, sizeof(Jucator), comparareJucatori);

    for (i = n - 1; i >= 0; i--)
    {
        if (count == n / m)
        {
            printf("\n");
            count = 0;
        }
        printf("%s %d\n", jucatori[i].nume, jucatori[i].valoare);
        count++;
    }
}

int main(void)
{
    p4();
    return 0;
}
