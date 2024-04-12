#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct elem{
 int n; // informatia utila
 struct elem *urm; // camp de inlantuire catre urmatorul element
 }elem;

elem *nou(int n, elem *urm)
{
 elem *e = (elem*)malloc(sizeof(elem));
 if(!e){
 printf("memorie insuficienta");
 exit(EXIT_FAILURE);
 }
 e->n = n;
 e->urm = urm;
 return e;
}

elem *adaugaInceput(elem *lista, int n)
{
 return nou(n, lista);
}

elem *adaugaSfarsit(elem **lista, int n)
{
 if(!(*lista)) return nou(n, NULL);
 elem *p = *lista, *urm;
 for(urm = p->urm; urm; p = urm, urm = p->urm){}
 p->urm = nou(n, NULL);
 return *lista;
}

int existaElement(elem *lista, int valoare) {
    while (lista != NULL) {
        if (lista->n == valoare) {
            return 1;
        }
        lista = lista->urm;
    }
    return 0;
}

// Aplicația 7.1: Să se scrie o funcție care primește două liste și returnează 1 dacă ele sunt identice, altfel 0.

int suntIdentice(elem *lista1, elem *lista2) {
    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->n != lista2->n) {
            return 0;
        }
        lista1 = lista1->urm;
        lista2 = lista2->urm;
    }
    if (lista1 == NULL && lista2 == NULL) {
        return 1;
    }
    return 0;
}

// Aplicația 7.2: Să se scrie o funcție care primește o listă și returnează lista respectivă cu elementele inversate.
// Funcția va acționa doar asupra listei originare, fără a folosi vectori sau alocare de noi elemente.

void inversareLista(elem **lista) {
    elem *prev = NULL;
    elem *current = *lista;
    elem *next = NULL;
    while (current != NULL) {
        next = current->urm;
        current->urm = prev;
        prev = current;
        current = next;
    }
    *lista = prev;
}

// Aplicația 7.3: Să se scrie o funcție care primește ca parametri două liste și returnează o listă care reprezintă
// reuniunea elementelor lor, fiecare element apărând o singură dată, chiar dacă în listele originare el este duplicat.

elem *reuniuneListe(elem *lista1, elem *lista2) {
    elem *rezultat = NULL;
    elem *temp = NULL;

    while (lista1 != NULL) {
        adaugaSfarsit(&rezultat, lista1->n);
        lista1 = lista1->urm;
    }

    while (lista2 != NULL) {
        if (!existaElement(rezultat, lista2->n)) {
            adaugaSfarsit(&rezultat, lista2->n);
        }
        lista2 = lista2->urm;
    }

    return rezultat;
}

// Aplicația 7.4: Pentru implementarea listei care memorează adresa ultimului element, să se scrie o funcție șterge,
// care șterge din listă un element dat

void sterge(elem **lista, int valoare) {
    elem *temp = *lista;
    elem *prev = NULL;

    if (temp != NULL && temp->n == valoare) {
        *lista = temp->urm;
        free(temp);
        return;
    }

    while (temp != NULL && temp->n != valoare) {
        prev = temp;
        temp = temp->urm;
    }

    if (temp == NULL) {
        return;
    }

    prev->urm = temp->urm;
    free(temp);
}

// Aplicația 7.5: Să se scrie o funcție care primește două liste și returnează 1 dacă ele sunt egale, indiferent de
// ordinea și numărul elementelor, altfel returnează 0.
// Exemple: listele {1, 7, 3, 1, 3} și {7, 1, 3, 7} sunt egale. Listele {1,2} și {2} nu sunt egale.

int suntEgale(elem *lista1, elem *lista2) {
    int frecventa1[1000] = {0}; // Presupunând că elementele sunt între 0 și 999
    int frecventa2[1000] = {0};

    while (lista1 != NULL) {
        frecventa1[lista1->n]++;
        lista1 = lista1->urm;
    }

    while (lista2 != NULL) {
        frecventa2[lista2->n]++;
        lista2 = lista2->urm;
    }

    for (int i = 0; i < 1000; i++) {
        if (frecventa1[i] != frecventa2[i]) {
            return 0;
        }
    }
    return 1;
}

// Aplicația 7.6: Să se scrie o funcție care primește ca parametri o listă (posibil vidă) de elemente sortate și un
// element. Funcția va insera în listă noul element, astfel încât lista să rămână sortată. Folosind aceasta funcție, să
// se scrie o funcție de sortare a unei liste, care primește ca parametru o listă nesortată și returnează una sortată.
// Programul nu va folosi niciun vector.

void inserareSortata(elem **lista, int valoare) {
    elem *nouElement = nou(valoare, NULL);
    elem *curent;

    if (*lista == NULL || (*lista)->n >= valoare) {
        nouElement->urm = *lista;
        *lista = nouElement;
    } else {
        curent = *lista;
        while (curent->urm != NULL && curent->urm->n < valoare) {
            curent = curent->urm;
        }
        nouElement->urm = curent->urm;
        curent->urm = nouElement;
    }
}

void sortareLista(elem **lista) {
    elem *sortata = NULL;
    elem *curent = *lista;
    elem *urmator;

    while (curent != NULL) {
        urmator = curent->urm;
        inserareSortata(&sortata, curent->n);
        curent = urmator;
    }
    *lista = sortata;
}

// Aplicația 7.7: Pentru implementarea listei care memorează ultimul element, să se scrie o funcție care primește
// două liste sortate și returnează lista sortată care conține toate elementele lor. Pentru lista rezultată se va folosi
// doar operația de adăugare la sfârșit de listă.
// Exemplu: {1, 2, 7, 8} și {2, 9} -> {1, 2, 2, 7, 8, 9}

elem *unireListeSortate(elem *lista1, elem *lista2) {
    elem *rezultat = NULL;

    while (lista1 != NULL && lista2 != NULL) {
        if (lista1->n <= lista2->n) {
            adaugaSfarsit(&rezultat, lista1->n);
            lista1 = lista1->urm;
        } else {
            adaugaSfarsit(&rezultat, lista2->n);
            lista2 = lista2->urm;
        }
    }

    while (lista1 != NULL) {
        adaugaSfarsit(&rezultat, lista1->n);
        lista1 = lista1->urm;
    }

    while (lista2 != NULL) {
        adaugaSfarsit(&rezultat, lista2->n);
        lista2 = lista2->urm;
    }

    return rezultat;
}

int main(){

    return 0;
}