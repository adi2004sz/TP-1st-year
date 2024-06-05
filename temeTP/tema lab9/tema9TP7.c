#include <stdio.h>
#include <stdlib.h>

// Aplicația 9.7: Se considera o lista liniara dublu inlantuita ale carei noduri sunt memorare cifre. Sa se scrie o functie
// care primeste ca parametru adresa primului nod al listei si verifica daca numarul care se compune din cifrele
// memorare in lista in ordine este sau nu palindrom. Functia va returna 1 daca este palindrom si 0 in caz contrar.

typedef struct Nod {
    int val;
    struct Nod *prev;
    struct Nod *next;
} Nod;

Nod* adaugaLaSfarsit(Nod *head, int val) {
    Nod *nou = (Nod *)malloc(sizeof(Nod));
    if (nou == NULL) {
        exit(EXIT_FAILURE);
    }
    nou->val = val;
    nou->prev = NULL;
    nou->next = NULL;
    if (head == NULL) {
        return nou;
    }
    Nod *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nou;
    nou->prev = temp;
    return head;
}

int estePalindrom(Nod *head) {
    if (head == NULL) {
        return 1;
    }

    Nod *start = head;
    Nod *end = head;
    while (end->next != NULL) {
        end = end->next;
    }

    while (start != end && end->next != start) {
        if (start->val != end->val) {
            return 0;
        }
        start = start->next;
        end = end->prev;
    }

    return 1;
}

int main() {
    FILE *fin = fopen("date.in", "r");
    FILE *fout = fopen("date.out", "w");
    if (fin == NULL || fout == NULL) {
        perror("Eroare la deschiderea fisierului");
        return EXIT_FAILURE;
    }

    Nod *lista = NULL;
    int num;
    while (fscanf(fin, "%d", &num) != EOF) {
        lista = adaugaLaSfarsit(lista, num);
    }

    int rezultat = estePalindrom(lista);

    fprintf(fout, "%d\n", rezultat);

    fclose(fin);
    fclose(fout);

    while (lista != NULL) {
        Nod *temp = lista;
        lista = lista->next;
        free(temp);
    }

    return 0;
}
