#include <stdio.h>
#include <stdlib.h>

// Aplicația 9.2: Se citesc numere intregi dintr-un fisier text. Sa se creeze 2 liste care sa contina in ordine elementele
// din fisier, una elementele pare, iar cealalta pe cele impare.


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

void adaugaListaLaSfarsit(Nod *head, Nod *toAdd) {
    if (head == NULL) {
        head = toAdd;
        return;
    }
    Nod *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = toAdd;
}

void afisareLista(Nod *head, FILE *fout) {
    Nod *temp = head;
    while (temp != NULL) {
        fprintf(fout, "%d ", temp->val);
        temp = temp->next;
    }
    fprintf(fout, "\n");
}

int main() {
    FILE *fin = fopen("date.in", "r");
    FILE *fout = fopen("date.out", "w");
    if (fin == NULL || fout == NULL) {
        perror("Eroare la deschiderea fisierului");
        return EXIT_FAILURE;
    }

    Nod *listaPare = NULL;
    Nod *listaImpare = NULL;
    int num;
    while (fscanf(fin, "%d", &num) != EOF) {
        if (num % 2 == 0) {
            listaPare = adaugaLaSfarsit(listaPare, num);
        } else {
            listaImpare = adaugaLaSfarsit(listaImpare, num);
        }
    }

    adaugaListaLaSfarsit(listaPare, listaImpare);

    afisareLista(listaPare, fout);

    fclose(fin);
    fclose(fout);

    //free
    while (listaPare != NULL) {
        Nod *temp = listaPare;
        listaPare = listaPare->next;
        free(temp);
    }

    return 0;
}
