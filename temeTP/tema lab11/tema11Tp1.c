#include <stdio.h>
#include <stdlib.h>

// Problema 11.1 Greedy

int origine[2][1];

int comparare(const void *a, const void *b)
{
    int x1, y1, x2, y2, dist1, dist2;
    x1 = ((int *)a)[0];
    y1 = ((int *)a)[1];
    x2 = ((int *)b)[0];
    y2 = ((int *)b)[1];
    dist1 = (x1 - origine[0][0]) * (x1 - origine[0][0]) + (y1 - origine[1][0]) * (y1 - origine[1][0]);
    dist2 = (x2 - origine[0][0]) * (x2 - origine[0][0]) + (y2 - origine[1][0]) * (y2 - origine[1][0]);
    return dist1 - dist2;
}

void p1(void)
{
    int n, coordonate[2][100], i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &coordonate[0][i], &coordonate[1][i]);
    }

    qsort(coordonate, n, 2 * sizeof(int), comparare);

    for (i = 0; i < n; i++)
    {
        printf("%d %d\n", coordonate[0][i], coordonate[1][i]);
    }
}

int main(void)
{
    p1();
    return 0;
}
