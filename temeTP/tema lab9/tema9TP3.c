#include <stdio.h>
#include <stdlib.h>

// Aplicația 9.3: Se considera o lista liniara simplu inlantuita care memoreaza valori intregi. Sa se scrie o functie care
// primeste ca parametru adresa primului nod al listei si insereaza dupa fiecare nod care memoreaza o valoare para
// un nod care sa memoreze jumatate din valoare acestuia.

typedef struct Nod {
    int val;
    struct Nod *next;
} Nod;

Nod* adaugaLaSfarsit(Nod *head, int val) {
    Nod *nou = (Nod *)malloc(sizeof(Nod));
    if (nou == NULL) {
        exit(EXIT_FAILURE);
    }
    nou->val = val;
    nou->next = NULL;
    if (head == NULL) {
        return nou;
    }
    Nod *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nou;
    return head;
}

void afisareLista(Nod *head, FILE *fout) {
    Nod *temp = head;
    while (temp != NULL) {
        fprintf(fout, "%d ", temp->val);
        temp = temp->next;
    }
    fprintf(fout, "\n");
}

void insereazaJumatateDupaPare(Nod *head) {
    Nod *temp = head;
    while (temp != NULL) {
        if (temp->val % 2 == 0) {
            Nod *nou = (Nod *)malloc(sizeof(Nod));
            if (nou == NULL) {
                exit(EXIT_FAILURE);
            }
            nou->val = temp->val / 2;
            nou->next = temp->next;
            temp->next = nou;
            temp = nou->next;
        } else {
            temp = temp->next;
        }
    }
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

    insereazaJumatateDupaPare(lista);

    afisareLista(lista, fout);

    fclose(fin);
    fclose(fout);

    // free
    while (lista != NULL) {
        Nod *temp = lista;
        lista = lista->next;
        free(temp);
    }

    return 0;
}
