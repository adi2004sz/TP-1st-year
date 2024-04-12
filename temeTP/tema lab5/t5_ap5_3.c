#include <stdio.h>
#include <stdlib.h>

// Aplicația 5.3: Se citesc m și n de la tastatură, iar apoi o matrice a[m][n] cu elemente de tip întreg. 
// Să se scrie matricea într-un fișier binar, prima oară scriindu-se m și n, iar apoi elementele, așa cum sunt dispuse ele în memorie. 
// Să se citească matricea din fișier într-o variabilă b și să se afișeze.

void scrieMatriceInFisier(const char* numeFisier, int m, int n, int a[][n]) {
    FILE* fisier = fopen(numeFisier, "wb");
    if (!fisier) {
        perror("Eroare deschiderea fisierului pentru scriere");
        exit(EXIT_FAILURE);
    }
    
    fwrite(&m, sizeof(int), 1, fisier);
    fwrite(&n, sizeof(int), 1, fisier);
    
    fwrite(a, sizeof(int), m*n, fisier);
    
    fclose(fisier);
}

void citesteMatriceDinFisier(const char* numeFisier, int* m, int* n, int*** a) {
    FILE* fisier = fopen(numeFisier, "rb");
    if (!fisier) {
        perror("Eroare deschiderea fisierului pentru citire");
        exit(EXIT_FAILURE);
    }
    
    fread(m, sizeof(int), 1, fisier);
    fread(n, sizeof(int), 1, fisier);
    
    *a = (int**) malloc(*m * sizeof(int*));
    for (int i = 0; i < *m; i++) {
        (*a)[i] = (int*) malloc(*n * sizeof(int));
    }
    
    for (int i = 0; i < *m; i++) {
        fread((*a)[i], sizeof(int), *n, fisier);
    }
    
    fclose(fisier);
}

void afiseazaMatrice(int m, int n, int** a) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("Introduceti m n: ");
    scanf("%d %d", &m, &n);
    
    int a[m][n];
    printf("Introduceti elementele :\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    scrieMatriceInFisier("matrice.bin", m, n, a);
    
    int **b, bm, bn;
    citesteMatriceDinFisier("matrice.bin", &bm, &bn, &b);
    
    printf("Matricea citita din fisier:\n");
    afiseazaMatrice(bm, bn, b);
    
    for (int i = 0; i < bm; i++) {
        free(b[i]);
    }
    free(b);

    return 0;
}
