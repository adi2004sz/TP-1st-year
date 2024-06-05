#include <stdio.h>
#include <stdlib.h>

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

void afisareLista(Nod *head, FILE *fout) {
    Nod *temp = head;
    while (temp != NULL) {
        fprintf(fout, "%d ", temp->val);
        temp = temp->next;
    }
    fprintf(fout, "\n");
}

Nod* stergePrimulSiUltimul(Nod *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Nod *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);

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

    lista = stergePrimulSiUltimul(lista);

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
