#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUSE 1000

// Aplicația 5.4: Să se modifice exemplul 4, astfel încât la începutul fișierului să fie scris numărul de produse.
// Citirea va fi modificată pentru a folosi această informație, în loc de a se testa sfârșitul de fișier.

typedef struct {
    char *nume;
    float pret;
} Produs;

Produs produse[MAX_PRODUSE];
int nProduse = 0;

void adaugare() {
    Produs p;
    char nume[1001];

    printf("nume: ");
    if (fgets(nume, sizeof(nume), stdin) == NULL) {
        printf("Eroare la citirea numelui\n");
        exit(EXIT_FAILURE);
    }
    nume[strcspn(nume, "\r\n")] = '\0';
    if ((p.nume = (char *)malloc((strlen(nume) + 1) * sizeof(char))) == NULL) {
        printf("memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }
    strcpy(p.nume, nume);
    printf("pret: ");
    if (scanf("%f", &p.pret) != 1) {
        printf("Eroare la citirea pretului\n");
        exit(EXIT_FAILURE);
    }
    while (getchar() != '\n');
    produse[nProduse] = p;
    nProduse++;
}

void afisare() {
    int i;
    for (i = 0; i < nProduse; i++) {
        printf("%s: %.2f\n", produse[i].nume, produse[i].pret);
    }
}

void scriere(int nProduse, Produs *produse) {
    FILE *fis;
    if ((fis = fopen("produse.dat", "wb")) == NULL) {
        printf("Nu se poate deschide fisierul pentru scriere\n");
        exit(EXIT_FAILURE);
    }
    fwrite(&nProduse, sizeof(int), 1, fis);
    fwrite(produse, sizeof(Produs), nProduse, fis);
    fclose(fis);
}

void citire(int *nProduse, Produs *produse) {
    FILE *fis;
    int nrProduseCitite = 0;

    if ((fis = fopen("produse.dat", "rb")) == NULL) {
        printf("Nu s-a putut deschide fisierul pentru citire\n");
        return;
    }

    fread(&nrProduseCitite, sizeof(int), 1, fis);

    if (nrProduseCitite > 0) {
        fread(produse, sizeof(Produs), nrProduseCitite, fis);
        *nProduse = nrProduseCitite;
    }

    fclose(fis);
}

void eliberare() {
    for (int i = 0; i < nProduse; i++) {
        free(produse[i].nume);
    }
}

int main() {
    int optiune;

    citire(&nProduse, produse);
    do {
        printf("\noptiune: ");
        if (scanf("%d", &optiune) != 1) {
            printf("Eroare la citirea optiunii\n");
            exit(EXIT_FAILURE);
        }
        while (getchar() != '\n');
        switch (optiune) {
            case 1:
                adaugare();
                break;
            case 2:
                afisare();
                break;
            case 3:
                scriere(nProduse, produse);
                eliberare();
                break;
            case 4:
                exit(EXIT_SUCCESS);
            default:
                printf("Optiune invalida\n");
        }
    } while (optiune != 4);
    return 0;
}
