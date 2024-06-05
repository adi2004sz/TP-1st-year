#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aplicația 8.4: Să se scrie un program care implementează o listă de categorii, fiecare categorie având asociată o
// listă de produse. O categorie se definește prin numele său. Un produs se definește prin nume și preț. Programul
// va prezenta utilizatorului un meniu cu următoarele opțiuni: 1-adaugă categorie; 2-adaugă produs (prima oară cere
// o categorie și apoi un produs pe care îl adaugă la acea categorie); 3-afișare categorii (afișează doar numele tuturor
// categoriilor); 4-afișare produse (cere o categorie și afișează toate produsele din ea); 5-ieșire

typedef struct produs
{
    char nume[50];
    int pret;
    struct produs *anterior, *urmator;
} Produs;

typedef struct categorie
{
    char nume[50];
    Produs *listaDeProduse;
    struct categorie *anterior, *urmator;
} Categorie;

Categorie *newCategorie(const char *nume)
{
    Categorie *nou = NULL;
    if ((nou = malloc(1 * sizeof(Categorie))) == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(nou->nume, nume);
    nou->anterior = NULL;
    nou->urmator = NULL;
    nou->listaDeProduse = NULL;
    return nou;
}

Categorie *adaugaCategorie(const char *nume, Categorie *listaDeCategorii)
{
    Categorie *nouaCategorie = newCategorie(nume), *aux;
    if (listaDeCategorii == NULL)
    {
        listaDeCategorii = nouaCategorie;
    }
    else
    {
        for (aux = listaDeCategorii; aux->urmator != NULL; aux = aux->urmator)
            ;
        aux->urmator = nouaCategorie;
        nouaCategorie->anterior = aux;
    }
    return listaDeCategorii;
}

Categorie *cautaCategorie(const char *nume, Categorie *listaDeCategorii)
{
    Categorie *aux;
    for (aux = listaDeCategorii; aux != NULL; aux = aux->urmator)
    {
        if (strcmp(nume, aux->nume) == 0)
        {
            return aux;
        }
    }
    return NULL;
}

void afisareCategorii(Categorie *listaDeCategorii)
{
    Categorie *aux;
    for (aux = listaDeCategorii; aux != NULL; aux = aux->urmator)
    {
        printf("%s\n", aux->nume);
    }
}

Produs *newProdus(const char *nume, int pret)
{
    Produs *nou = NULL;
    if ((nou = malloc(1 * sizeof(Produs))) == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(nou->nume, nume);
    nou->pret = pret;
    nou->anterior = NULL;
    nou->urmator = NULL;
    return nou;
}

Categorie *adaugaProdus(const char *numeProdus, int pret, const char *numeCategorie, Categorie *listaDeCategorii)
{
    Produs *nouProdus = newProdus(numeProdus, pret), *aux;
    Categorie *categorieCautata = NULL;
    categorieCautata = cautaCategorie(numeCategorie, listaDeCategorii);
    if (categorieCautata->listaDeProduse == NULL)
    {
        categorieCautata->listaDeProduse = nouProdus;
    }
    else
    {
        for (aux = categorieCautata->listaDeProduse; aux->urmator != NULL; aux = aux->urmator)
            ;
        aux->urmator = nouProdus;
        nouProdus->anterior = aux;
    }
    return listaDeCategorii;
}

void afisareProduse(const char *nume, Categorie *listaDeCategorii)
{
    Categorie *auxC;
    Produs *auxP;
    auxC = cautaCategorie(nume, listaDeCategorii);
    if (auxC != NULL)
    {
        for (auxP = auxC->listaDeProduse; auxP != NULL; auxP = auxP->urmator)
        {
            printf("%s costa %d\n", auxP->nume, auxP->pret);
        }
    }
}

void freeProduse(Produs *listaDeProduse)
{
    Produs *curent = listaDeProduse;
    Produs *urm = NULL;
    while (curent != NULL)
    {
        urm = curent->urmator;
        free(curent);
        curent = urm;
    }
}

void freeCategorii(Categorie *listaDeCategorii)
{
    Categorie *curent = listaDeCategorii;
    Categorie *urmator = NULL;
    while (curent != NULL)
    {
        freeProduse(curent->listaDeProduse);
        urmator = curent->urmator;
        free(curent);
        curent = urmator;
    }
}

void p4(void)
{
    int optiune, pret;
    char numeCategorie[50], numeProdus[50];
    Categorie *listaDeCategorii = NULL;
    do
    {
        printf("Optiuni:\n1. Adauga categorie\n2. Adauga produs\n3. Afiseaza categorii\n4. Afiseaza produse\n5. Iesire\n");
        scanf("%d", &optiune);
        switch (optiune)
        {
        case 1:
        {
            printf("Introduceti numele categoriei: ");
            scanf("%49s", numeCategorie);
            listaDeCategorii = adaugaCategorie(numeCategorie, listaDeCategorii);
            break;
        }
        case 2:
        {
            printf("Introduceti numele categoriei: ");
            scanf("%49s", numeCategorie);
            printf("Introduceti numele produsului: ");
            scanf("%49s", numeProdus);
            printf("Introduceti pretul produsului: ");
            scanf("%d", &pret);
            listaDeCategorii = adaugaProdus(numeProdus, pret, numeCategorie, listaDeCategorii);
            break;
        }
        case 3:
        {
            afisareCategorii(listaDeCategorii);
            break;
        }
        case 4:
        {
            printf("Introduceti numele categoriei: ");
            scanf("%49s", numeCategorie);
            afisareProduse(numeCategorie, listaDeCategorii);
            break;
        }
        case 5:
        {
            freeCategorii(listaDeCategorii);
            break;
        }
        default:
        {
            printf("Optiune invalida\n");
            break;
        }
        }
    } while (optiune != 5);
}

int main(void)
{
    p4();
    return 0;
}
