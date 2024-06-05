#include <stdio.h>

// Problema 11.3 Divide et Impera

int reduceMatrix(int matrice[][100], int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    else if (m == 1 && n == 1)
    {
        return matrice[0][0];
    }
    else
    {
        int mijlocRand = m / 2;
        int mijlocColoana = n / 2;

        int stangaSus[100][100], dreaptaSus[100][100], stangaJos[100][100], dreaptaJos[100][100];

        for (int i = 0; i < mijlocRand; i++)
        {
            for (int j = 0; j < mijlocColoana; j++)
            {
                stangaSus[i][j] = matrice[i][j];
            }
        }

        for (int i = 0; i < mijlocRand; i++)
        {
            for (int j = mijlocColoana; j < n; j++)
            {
                dreaptaSus[i][j - mijlocColoana] = matrice[i][j];
            }
        }

        for (int i = mijlocRand; i < m; i++)
        {
            for (int j = 0; j < mijlocColoana; j++)
            {
                stangaJos[i - mijlocRand][j] = matrice[i][j];
            }
        }

        for (int i = mijlocRand; i < m; i++)
        {
            for (int j = mijlocColoana; j < n; j++)
            {
                dreaptaJos[i - mijlocRand][j - mijlocColoana] = matrice[i][j];
            }
        }

        int reducereStangaSus = reduceMatrix(stangaSus, mijlocRand, mijlocColoana);
        int reducereDreaptaSus = reduceMatrix(dreaptaSus, mijlocRand, n - mijlocColoana);
        int reducereStangaJos = reduceMatrix(stangaJos, m - mijlocRand, mijlocColoana);
        int reducereDreaptaJos = reduceMatrix(dreaptaJos, m - mijlocRand, n - mijlocColoana);

        int maximSus = (reducereStangaSus > reducereDreaptaSus) ? reducereStangaSus : reducereDreaptaSus;
        int minimJos = (reducereStangaJos < reducereDreaptaJos) ? reducereStangaJos : reducereDreaptaJos;

        return maximSus - minimJos;
    }
}

void p3(void)
{
    int m, n, matrice[100][100], i, j;
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrice[i][j]);
        }
    }

    printf("%d\n", reduceMatrix(matrice, m, n));
}

int main(void)
{
    p3();
    return 0;
}
