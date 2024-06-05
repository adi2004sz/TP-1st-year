#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aplicația 8.3: Să se scrie un program care primește un nume de fișier în linia de comandă. Programul va citi toate
// liniile din fișier într-o listă care este mereu sortată în ordine alfabetică. O linie poate avea maxim 1000 de caractere.
// Pentru ca lista să fie mereu sortată alfabetic, adăugarea unei linii noi se face prin inserarea ei la poziția corectă din
// listă, astfel încât să se mențină proprietatea de sortare. În final se va afișa lista.

typedef struct nod
{
    char info[1000];
    struct nod *ant, *urm;
} Nod;

Nod *nouNod(const char *info)
{
    Nod *nouNod = NULL;
    if ((nouNod = (Nod *)malloc(sizeof(Nod))) == NULL)
    {
        printf("Memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(nouNod->info, info);
    nouNod->ant = NULL;
    nouNod->urm = NULL;
    return nouNod;
}

Nod *adaugaNod(Nod *lista, const char *info)
{
    Nod *nou = nouNod(info);
    if (lista == NULL)
    {
        return nou;
    }
    else if (strcmp(info, lista->info) < 0)
    {
        nou->urm = lista;
        lista->ant = nou;
        return nou;
    }
    else
    {
        Nod *curent = lista;
        while (curent->urm != NULL && strcmp(info, curent->urm->info) > 0)
        {
            curent = curent->urm;
        }
        nou->urm = curent->urm;
        if (curent->urm != NULL)
        {
            curent->urm->ant = nou;
        }
        curent->urm = nou;
        nou->ant = curent;
        return lista;
    }
}

void afisareLista(Nod *lista)
{
    Nod *curent = lista;
    while (curent != NULL)
    {
        printf("%s", curent->info);
        curent = curent->urm;
    }
}

void freeLista(Nod *lista)
{
    Nod *curent = lista;
    Nod *urm = NULL;
    while (curent != NULL)
    {
        urm = curent->urm;
        free(curent);
        curent = urm;
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Utilizare: %s <fisier>\n", argv[0]);
        return 1;
    }

    FILE *fisier = NULL;
    Nod *lista = NULL;
    char buffer[1000];

    if ((fisier = fopen(argv[1], "r")) == NULL)
    {
        printf("Eroare la deschiderea fisierului");
        return 1;
    }

    while (fgets(buffer, 1000, fisier) != NULL)
    {
        lista = adaugaNod(lista, buffer);
    }

    afisareLista(lista);

    freeLista(lista);

    fclose(fisier);
    return 0;
}
