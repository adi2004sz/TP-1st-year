#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// //Aplicația 8.1: Să se modifice exemplul 1 astfel încât el să numere de câte ori apare fiecare cuvânt în propoziție.
// Pentru aceasta, cuvintele vor fi adăugate doar cu litere mici și fiecare cuvânt va avea asociat un contor. Dacă un
// cuvânt nou nu există în propoziție, el va fi adăugat. Altfel, dacă el există deja, doar se va incrementa contorul
// cuvântului existent. La afișare, pentru fiecare cuvânt se va afișa și contorul său.

// Aplicația 8.2: La exemplul 1 să se adauge operația de inserare a unui cuvânt. Pentru aceasta se cere un cuvânt
// de inserat și un cuvânt succesor. Dacă succesorul există în propoziție, cuvântul de inserat va fi inserat înaintea sa.
// Dacă succesorul nu există în lista, cuvântul de inserat va fi adăugat la sfârșitul listei.


typedef struct Cuvant
{
    char text[16];
    int count;
    struct Cuvant *pred;
    struct Cuvant *urm;
} Cuvant;

Cuvant *Cuvant_nou(const char *text)
{
    Cuvant *c = (Cuvant *)malloc(sizeof(Cuvant));
    if (!c)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(c->text, text);
    c->count = 1;
    c->pred = NULL;
    c->urm = NULL;
    return c;
}

typedef struct
{
    Cuvant *prim;
    Cuvant *ultim;
} Propozitie;

void Propozitie_init(Propozitie *p)
{
    p->prim = p->ultim = NULL;
}

Cuvant *Propozitie_cauta(Propozitie *p, const char *text)
{
    Cuvant *c;
    for (c = p->prim; c; c = c->urm)
    {
        if (!strcmp(c->text, text))
            return c;
    }
    return NULL;
}

void Propozitie_adauga(Propozitie *p, Cuvant *c)
{
    Cuvant *exista = Propozitie_cauta(p, c->text);
    if (exista)
    {
        exista->count++;
        free(c);
    }
    else
    {
        c->pred = p->ultim;
        if (p->ultim)
        {
            p->ultim->urm = c;
        }
        else
        {
            p->prim = c;
        }
        p->ultim = c;
        c->urm = NULL;
    }
}

void Propozitie_sterge(Propozitie *p, Cuvant *c)
{
    if (c->pred)
    {
        c->pred->urm = c->urm;
    }
    else
    {
        p->prim = c->urm;
    }
    if (c->urm)
    {
        c->urm->pred = c->pred;
    }
    else
    {
        p->ultim = c->pred;
    }
    free(c);
}

void Propozitie_elibereaza(Propozitie *p)
{
    Cuvant *c, *urm;
    for (c = p->prim; c; c = urm)
    {
        urm = c->urm;
        free(c);
    }
    Propozitie_init(p);
}

void Propozitie_inserare(Propozitie *p, const char *cuvant_inserat, const char *cuvant_succesor)
{
    Cuvant *inserat = Cuvant_nou(cuvant_inserat);
    Cuvant *succesor = Propozitie_cauta(p, cuvant_succesor);

    if (succesor)
    {
        inserat->pred = succesor->pred;
        inserat->urm = succesor;
        if (succesor->pred)
        {
            succesor->pred->urm = inserat;
        }
        else
        {
            p->prim = inserat;
        }
        succesor->pred = inserat;
    }
    else
    {
        Propozitie_adauga(p, inserat);
    }
}

void afisarePropozitie(Propozitie *p)
{
    Cuvant *c;
    for (c = p->prim; c; c = c->urm)
    {
        printf("%s (%d)\n", c->text, c->count);
    }
}

int main()
{
    Propozitie p;
    Propozitie_init(&p);

    char cuvinte[][16] = {"cuvant", "test", "cuvant", "propozitie", "test", "altul"};
    for (int i = 0; i < 6; i++)
    {
        Cuvant *c = Cuvant_nou(cuvinte[i]);
        Propozitie_adauga(&p, c);
    }

    printf("Propozitia dupa adaugare:\n");
    afisarePropozitie(&p);

    printf("Inserez cuvantul 'inainte' inainte de 'test'\n");
    Propozitie_inserare(&p, "inainte", "test");
    afisarePropozitie(&p);

    Propozitie_elibereaza(&p);
    return 0;
}
