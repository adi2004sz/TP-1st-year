#include <stdio.h>
#include <stdbool.h>

// &a[0][0] + i * nr_coloane + j <=> a[i][j]

// #### FUNCTII AUXILIARE #####

#define MAX_M 20
#define MAX_N 20

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void citesteMatrice(int matrice[MAX_M][MAX_N], int m, int n) {
    printf("Introduceti %d x %d:\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elementul [%d][%d]: ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
}

void citesteMatricePatrat(int (*matrice)[MAX_N], int n) {
    printf("Introduceti:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", (matrice + i * n + j));
        }
    }
}

void sumaPeLinii(int  (*matrice)[MAX_N], int *sumaLinii, int n) {
    for (int i = 0; i < n; i++) {
        sumaLinii[i] = 0;
        for (int j = 0; j < n; j++) {
            sumaLinii[i] += *(*(matrice + i) + j);
        }
    }
}

void sumaPeColoane(int  (*matrice)[MAX_N], int *sumaColoane, int n) {
    for (int j = 0; j < n; j++) {
        sumaColoane[j] = 0;
        for (int i = 0; i < n; i++) {
            sumaColoane[j] += *(*(matrice + i) + j);
        }
    }
}

void afiseazaVector(int *vector, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(vector + i));
    }
    printf("\n");
}

void afiseazaMatrice(int matrice[MAX_M][MAX_N], int linii, int coloane) {
    for (int i = 0; i < linii; i++) {
        for (int j = 0; j < coloane; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}
bool inCrestereContinua(int vector[], int dimensiune) {
    for (int i = 1; i < dimensiune; i++) {
        if (vector[i] <= vector[i - 1]) {
            return false;
        }
    }
    return true;
}

// #### FUNCTII PROBLEME ####


//Aplicația 8.3: Se citește de la tastatură un număr n<=10 și un număr m<=20. Se cere să se scrie un program care
//generează o matrice cu m linii și n coloane în care sunt puse toate numerele de la 1,2,3,...,m*n. Se vor utiliza
//pointeri.

void prog8_3(int m , int n){
    // Problema exclusiv cu pointeri
    int a[m][n];
    int i, j;
    for (i = 0; i < m; i++)
    {
        for(j=0;j<n;j++)
        {
            *(&a[0][0] + i * n + j ) = j+i*n+1;
        }
    }
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            printf("%d ", *(&a[0][0] + i * n + j ));
        }
        printf("\n");
    }
}

// Aplicația 8.4: Se citește de la tastatură o matrice pătratică cu n<=50 linii și coloane. Să se interschimbe elementele
// de deasupra diagonalei principale, considerată ca axă de simetrie, cu elementele de sub diagonala principală,
// elementele de pe diagonala principală rămânând la fel. De exemplu matricea:
// 1 2 3
// 4 5 6
// 7 8 9
// Va deveni:
// 1 4 7
// 2 5 8
// 3 6 9

void prog8_4(int n){
    int a[n][n];
    citesteMatricePatrat((int *)a, n);

    printf("\n");

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i!=j){
                swap(&a[i][j],&a[j][i]);
            }
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// Aplicația 8.5: Se citește de la tastatură o matrice cu n<=20 linii și coloane. Să se memoreze într-un vector suma
// tuturor elementelor de pe fiecare linie și într-un alt vector, suma tuturor elementelor de pe fiecare coloană. Să se
// afișeze cei doi vectori. Se vor utiliza pointeri atât pentru vectori cât și pentru matrici.

void prog8_5(int n)
{
    int matrice[n][n];
    int sumaLinii[n];
    int sumaColoane[n];
    // abordare LEGO
    citesteMatricePatrat(matrice, n);

    sumaPeLinii(matrice, sumaLinii, n);
    sumaPeColoane(matrice, sumaColoane, n);

    afiseazaVector(sumaLinii, n);
    printf("\n");
    afiseazaVector(sumaColoane, n);
}

// Aplicația 8.6: Se citește un număr n<=10 de persoane, fiecare persoană fiind identificată printr-un număr între
// 0..n-1. O persoană poate fi prietenă cu oricare alte persoane. După ce s-a citit n, se vor citi pentru fiecare persoană
// prietenii ei pe rând. Să se afișeze pentru fiecare persoană câți prieteni are.

void prog8_6(int n)
{
    int prieteni[n][n];
    int numarPrieteni[n];

    for (int i = 0; i < n; i++) {
        printf("Introduceti numarul de prieteni pentru persoana %d: ", i);
        scanf("%d", &numarPrieteni[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("Introduceti numerele de identificare ale prietenilor pentru persoana %d:\n", i);
        for (int j = 0; j < numarPrieteni[i]; j++) {
            scanf("%d", &prieteni[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        int numarPrieteniTotal = 0;
        for (int j = 0; j < numarPrieteni[i]; j++) {
            numarPrieteniTotal++;
        }
        numarPrieteni[i] = numarPrieteniTotal;
    }
    printf("Numarul de prieteni pentru fiecare persoana:\n");
    for (int i = 0; i < n; i++) {
        printf("Persoana %d are %d prieteni.\n", i, numarPrieteni[i]);
    }
}

// Aplicația 8.7: Se citește un număr n<=10 de orașe și apoi pentru fiecare 2 orașe se citește distanța directă dintre
// ele. Dacă distanța este 0, înseamnă că între acele orașe nu există drum direct. Să se afișeze perechea de orașe
// cele mai apropiate între ele în mod direct.

void prog8_7(int n)
{
    int distante[n][n]; // Matricea de distante
    char orase[n][20]; // Vectorul pentru a memora numele oraselor
    int oras1, oras2; // Indicii orașelor cele mai apropiate

    for (int i = 0; i < n; i++) {
        printf("Orasul %d: ", i);
        scanf("%s", orase[i]);
    }
    printf("Introduceti distantele directe intre orase:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Distanta intre %s si %s: ", orase[i], orase[j]);
            scanf("%d", &distante[i][j]);
        }
    }
    int ceaMaiMicaDistanta = 999999;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (distante[i][j] < ceaMaiMicaDistanta && distante[i][j] != 0) {
                ceaMaiMicaDistanta = distante[i][j];
                oras1 = i;
                oras2 = j;
            }
        }
    }
}

// Aplicația 8.8: Se citesc numerele m,n,p fiecare mai mici decat 10, apoi se citesc matricile a[m][n] și b[n][p]. Se
// cere să se calculeze matricea „c” care rezultă din înmulțirea matricilor a cu b și să se afișeze.

void prog8_8(int m,int n,int p)
{
    int a[m][n],b[n][p],c[m][p];
    citesteMatricePatrat((int *)a, m,n);
    citesteMatricePatrat((int *)b, n,p);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    afiseazaMatrice((int **) c, m, p);
}

// Aplicația 8.9: Se citește un număr n<=10. Se cere să se inițializeze o matrice a[n][n] cu 1 pe diagonale și cu 0 în
// rest. Să se afișeze matricea.

void prog8_9(int n)
{
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i==j){
                a[i][j]=1;
            } else{
                a[i][j] = 0;
            }
        }
    }
    afiseazaMatrice(a, n, n);
}

// Aplicația 8.10: Se citește un număr n<=10 de produse și pentru fiecare produs vânzările lui trimestriale pe un an
// (4 valori). Se cere să se afișeze care produse au înregistrat o creștere continuă a vânzărilor în decurs de un an.

void prog8_10(int n)
{
    int vanzari[n][4];
    citesteMatrice( vanzari, n, 4);
    printf("Produsele cu vanzari in crestere continua:\n");
    for (int i = 0; i < n; i++) {
        if (inCrestereContinua(vanzari[i], 4)) {
            printf("Produsul %d\n", i + 1);
        }
    }
}
int main() {
    int m = 0, n = 0, p = 0;
    scanf("%d", &m);
    scanf("%d", &n);
    scanf("%d", &p);
    
    //prog8_3(m, n);
    //prog8_4(n);
    //prog8_5(n);
    //prog8_6(n);
    //prog8_7(n);
    //prog8_8(m, n, p);
    //prog8_9(n);
    //prog8_10(n);
    
    return 0;
}

