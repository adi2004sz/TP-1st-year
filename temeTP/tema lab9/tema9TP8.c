#include <stdio.h>
#include <stdlib.h>

// Aplicația 9.8: Sa se scrie o functie care primeste ca parametru adresa primului nod al unei liste liniare simplu
// inlantuite cu cel putin 3 noduri si muta primul nod al listei dupa ultimul nod al listei.

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

Nod* mutaPrimulDupaUltimul(Nod *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Nod *primul = head;
    Nod *ultimul = head;

    while (ultimul->next != NULL) {
        ultimul = ultimul->next;
    }

    head = head->next;
    primul->next = NULL;
    ultimul->next = primul;

    return head;
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

    lista = mutaPrimulDupaUltimul(lista);

    afisareLista(lista, fout);

    fclose(fin);
    fclose(fout);

    while (lista != NULL) {
        Nod *temp = lista;
        lista = lista->next;
        free(temp);
    }

    return 0;
}
