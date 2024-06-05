#include <stdio.h>
#include <stdlib.h>

// Aplicația 9.1: Din fisierul date.in se citeste un numar natural k si apoi de pe a doua linie numere intregi. Contruiti
// o lista liniara simplu inlantuita care sa contina numerele intregi citite in ordinea din fisier.
// Permutati lista cu k pozitii spre stanga si afisati valorile din lista.
// Indicatie: se vor scrie si folosi functii pentru adaugarea unei valori la sfarsitul listei si pentru stergerea primului nod
// al listei si vor fi folosite pentru permuarea ceruta.
// Exemplu:
// date.in
// 3
// 1 2 3 4
// date.out
// 4 1 2 3

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

Nod* stergePrimulNod(Nod *head) {
    if (head == NULL) {
        return NULL;
    }
    Nod *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Nod* permutaLista(Nod *head, int k) {
    for (int i = 0; i < k; i++) {
        if (head == NULL) {
            return NULL;
        }
        int val = head->val;
        head = stergePrimulNod(head);
        head = adaugaLaSfarsit(head, val);
    }
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

int main() {
    FILE *fin = fopen("date.in", "r");
    FILE *fout = fopen("date.out", "w");
    if (fin == NULL || fout == NULL) {
        perror("Eroare la deschiderea fisierului");
        return EXIT_FAILURE;
    }

    int k;
    fscanf(fin, "%d", &k);

    Nod *lista = NULL;
    int num;
    while (fscanf(fin, "%d", &num) != EOF) {
        lista = adaugaLaSfarsit(lista, num);
    }

    lista = permutaLista(lista, k);

    afisareLista(lista, fout);

    fclose(fin);
    fclose(fout);

    //free
    while (lista != NULL) {
        lista = stergePrimulNod(lista);
    }

    return 0;
}
