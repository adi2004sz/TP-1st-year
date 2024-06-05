#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aplicația 8.5: Să se imlementeze o listă dublu înlănțuită care gestionează un parc de automobile. Informaţiile
// relative la un automobil sunt: codul mașinii (număr între 1 si 9000), numărul de locuri (între 1 și 9), puterea (în cai
// putere între 1 și 500), marca, culoarea, anul fabricaţiei maşinii (între 1800 și 2017). Parcul conține n automobile,
// datele sunt citite de la tastatură. Să se scrie următoarele funcții de gestiune a mașinilor:
// a) Introducerea unui automobil nou în listă la începutul listei;
// b) Ștergerea unui anumit automobil din listă, al cărui cod e citit de la tastatură;
// c) Afișarea întregii liste pe ecran;
// d) Afișarea pe ecran doar a automobilelor cu un anumit număr de locuri, citit de la tastatură;
// e) Ordonarea listei în funcție de anul fabricației.


typedef struct automobil
{
    unsigned int codMasina : 14;
    unsigned int numarLocuri : 4;
    unsigned int putere : 9;
    char marca[50];
    char culoare[50];
    unsigned int anulFabricatiei : 11;
    struct automobil *anterior;
    struct automobil *urmator;
} Automobil;

Automobil *adaugaAutomobil(unsigned int codMasina, unsigned int numarLocuri, unsigned int putere, const char *marca, const char *culoare, unsigned int anulFabricatiei, Automobil *listaDeMasini)
{
    Automobil *nou = NULL;
    if ((nou = malloc(1 * sizeof(Automobil))) == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nou->codMasina = codMasina;
    nou->numarLocuri = numarLocuri;
    nou->putere = putere;
    strcpy(nou->marca, marca);
    strcpy(nou->culoare, culoare);
    nou->anulFabricatiei = anulFabricatiei;
    nou->anterior = NULL;
    nou->urmator = NULL;
    if (listaDeMasini == NULL)
    {
        return nou;
    }
    else
    {
        nou->urmator = listaDeMasini;
        listaDeMasini->anterior = nou;
    }
    return nou;
}

Automobil *stergeAutomobil(unsigned int codMasina, Automobil *listaDeMasini)
{
    Automobil *aux = listaDeMasini;
    while (aux != NULL && aux->codMasina != codMasina)
    {
        aux = aux->urmator;
    }
    if (aux == NULL)
    {
        return listaDeMasini;
    }
    if (aux->anterior != NULL)
    {
        aux->anterior->urmator = aux->urmator;
    }
    if (aux->urmator != NULL)
    {
        aux->urmator->anterior = aux->anterior;
    }
    if (aux == listaDeMasini)
    {
        listaDeMasini = aux->urmator;
    }
    free(aux);
    return listaDeMasini;
}

void afisareAutomobile(Automobil *listaDeAutomobile)
{
    Automobil *aux;
    for (aux = listaDeAutomobile; aux != NULL; aux = aux->urmator)
    {
        printf("Cod masina: %d\n", aux->codMasina);
        printf("Numar locuri: %d\n", aux->numarLocuri);
        printf("Putere: %d\n", aux->putere);
        printf("Marca: %s\n", aux->marca);
        printf("Culoare: %s\n", aux->culoare);
        printf("Anul fabricatiei: %d\n", aux->anulFabricatiei);
    }
}

void afisareAutomobileNumarLocuri(int numarLocuriCautate, Automobil *listaDeAutomobile)
{
    Automobil *aux;
    for (aux = listaDeAutomobile; aux != NULL; aux = aux->urmator)
    {
        if (aux->numarLocuri == numarLocuriCautate)
        {
            printf("Cod masina: %d\n", aux->codMasina);
            printf("Numar locuri: %d\n", aux->numarLocuri);
            printf("Putere: %d\n", aux->putere);
            printf("Marca: %s\n", aux->marca);
            printf("Culoare: %s\n", aux->culoare);
            printf("Anul fabricatiei: %d\n", aux->anulFabricatiei);
        }
    }
}

Automobil *sortareAnFabricatie(Automobil *listaDeAutomobile)
{
    Automobil *aux, *aux2;
    for (aux = listaDeAutomobile; aux != NULL; aux = aux->urmator)
    {
        for (aux2 = aux->urmator; aux2 != NULL; aux2 = aux2->urmator)
        {
            if (aux->anulFabricatiei > aux2->anulFabricatiei)
            {
                // Swap
                unsigned int tempCodMasina = aux->codMasina;
                aux->codMasina = aux2->codMasina;
                aux2->codMasina = tempCodMasina;

                unsigned int tempNumarLocuri = aux->numarLocuri;
                aux->numarLocuri = aux2->numarLocuri;
                aux2->numarLocuri = tempNumarLocuri;

                unsigned int tempPutere = aux->putere;
                aux->putere = aux2->putere;
                aux2->putere = tempPutere;

                char tempMarca[50];
                strcpy(tempMarca, aux->marca);
                strcpy(aux->marca, aux2->marca);
                strcpy(aux2->marca, tempMarca);

                char tempCuloare[50];
                strcpy(tempCuloare, aux->culoare);
                strcpy(aux->culoare, aux2->culoare);
                strcpy(aux2->culoare, tempCuloare);

                unsigned int tempAnulFabricatiei = aux->anulFabricatiei;
                aux->anulFabricatiei = aux2->anulFabricatiei;
                aux2->anulFabricatiei = tempAnulFabricatiei;
            }
        }
    }
    return listaDeAutomobile;
}

void freeAutomobile(Automobil *listaDeAutomobile)
{
    Automobil *curent = listaDeAutomobile;
    Automobil *urm = NULL;
    while (curent != NULL)
    {
        urm = curent->urmator;
        free(curent);
        curent = urm;
    }
}

void p5(void)
{
    int optiune;
    unsigned int codMasina, numarLocuri, putere, anulFabricatiei;
    char marca[50], culoare[50];
    Automobil *listaDeAutomobile = NULL;
    do
    {
        scanf("%d", &optiune);
        switch (optiune)
        {
        case 1:
        {
            scanf("%d", &codMasina);
            scanf("%d", &numarLocuri);
            scanf("%d", &putere);
            scanf("%49s", marca);
            scanf("%49s", culoare);
            scanf("%d", &anulFabricatiei);
            listaDeAutomobile = adaugaAutomobil(codMasina, numarLocuri, putere, marca, culoare, anulFabricatiei, listaDeAutomobile);
            break;
        }
        case 2:
        {
            scanf("%d", &codMasina);
            listaDeAutomobile = stergeAutomobil(codMasina, listaDeAutomobile);
            break;
        }
        case 3:
        {
            afisareAutomobile(listaDeAutomobile);
            break;
        }
        case 4:
        {
            scanf("%d", &numarLocuri);
            afisareAutomobileNumarLocuri(numarLocuri, listaDeAutomobile);
            break;
        }
        case 5:
        {
            listaDeAutomobile = sortareAnFabricatie(listaDeAutomobile);
            break;
        }
        case 6:
        {
            freeAutomobile(listaDeAutomobile);
            break;
        }
        }
    } while (optiune != 6);
}

int main(void)
{
    p5();
    return 0;
}
