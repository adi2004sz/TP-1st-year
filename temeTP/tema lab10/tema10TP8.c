#include <stdio.h>

// Aplicația 10.8: Să se implementeze cu o functie recursivă căutarea binară pe un vector ordonat (Binary Search -
// bsearch). Functia trebuie să returneze dacă numărul căutat există sau nu în vector. Principiul după care
// funcționează bsearch este că vectorul se împarte la fiecare pas în 2 vectori de dimensiuni egale (sau aproximativ
// egale) și continuă căutarea doar în unul dintre ei (apelează recursiv funcția de căutare doar pe jumătate din vectorul
// inițial), cel din partea stângă sau cel din partea dreaptă, în funcție de valoarea numărului căutat.

int binarySearch(int *v, int st, int dr, int x)
{
    if (st > dr)
    {
        return -1;
    }
    else
    {
        int mij = (st + dr) / 2;
        if (v[mij] == x)
        {
            return mij;
        }
        else if (v[mij] < x)
        {
            return binarySearch(v, mij + 1, dr, x);
        }
        else
        {
            return binarySearch(v, st, mij - 1, x);
        }
    }
}

void p8(void)
{
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result = binarySearch(v, 0, 8, 5);
    if(result != -1)
    {
        printf("Elementul a fost gasit la indexul %d\n", result);
    }
    else
    {
        printf("Elementul nu a fost gasit\n");
    }
}

int main(void)
{
    p8();
    return 0;
}
