#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Result {
    char name[50];
    int score;
};

int compare(const void *a, const void *b) {
    const struct Result *resultA = (const struct Result *)a;
    const struct Result *resultB = (const struct Result *)b;

    if (resultA->score != resultB->score) {
        return resultB->score - resultA->score;
    } else {
        // in cazul in care notele sunt identice, sortam alfabetic dupa nume
        return strcmp(resultA->name, resultB->name);
    }
}

int isNegative(int x) {
    return x < 0;
}

void filterArray(int *array, int *n, int (*predicate)(int)) {
    int count = 0; 

    // Parcurgem vectorul si copiem elementele care indeplinesc conditia in pozitiile dorite
    for (int i = 0; i < *n; i++) {
        if (predicate(array[i])) {
            array[count++] = array[i];
        }
    }

    // Actualizam numarul de elemente
    *n = count;
}

// Funcție de comparare pentru qsort problema 2.3
int compare2_3(const void *a, const void *b) {
    const float *floatA = (const float *)a;
    const float *floatB = (const float *)b;
    
    if (*floatA < *floatB) return -1;
    if (*floatA > *floatB) return 1;
    return 0;
}

// Definirea tipului de pointer la functie
typedef double (*MathFunction)(double);

// Functia de tabelare
void tabulate(double a, double b, int n, MathFunction f) {
    double step = (b - a) / n;
    double x = a;

    // Tabelarea si afisarea valorilor
    for (int i = 0; i <= n; i++) {
        printf("f(%.2f) = %.2f\n", x, f(x));
        x += step;
    }
}

//############## REZOLVARE PROBLEME EFECTIVE ###################

// Aplicația 2.1: Se cere un număr n și apoi un vector de n rezultate ale studenților la un examen. Fiecare rezultat
// este definit prin (nume,nota). Se cere să se sorteze folosind qsort vectorul în ordinea notelor, notele cele mai mari
// fiind primele. Dacă două note sunt identice, rezultatele respective se vor sorta în ordinea alfabetică a numelor.

void p1()
{
    int n;
    scanf("%d",&n);
    struct Result *results = (struct Result *)malloc(n * sizeof(struct Result));

    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%s %d", results[i].name, &results[i].score);
    }

        qsort(results, n, sizeof(struct Result), compare);

    for (int i = 0; i < n; i++) {
        printf("%s %d\n", results[i].name, results[i].score);

            free(results);
    }
}

// Aplicația 2.2: Să se implementeze o funcție care primește ca parametri un vector de întregi, numărul elementelor
// din vector transmis prin adresă și un predicat care testează dacă un întreg îndeplinește o anumită condiție. Funcția
// va sterge din vector toate elementele care nu îndeplinesc condiția dată și va actualiza numărul elementelor cu
// numărul de elemente rămas în vector. Să se testeze funcția cu un predicat care testează dacă un număr este
// negativ și să se afișeze vectorul rezultat

void p2()
{
    int n;
    scanf("%d",&n);

    int *array = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Elementul %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // vectorul initial
    printf("\nVector initial: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    //filtrare cu predicatul isNegative ()
    filterArray(array, &n, isNegative);

    // vectorul dupa filtrare
    printf("Vector dupa filtrare: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
}

// Aplicația 2.3: Se introduce un număr întreg n<10 și apoi n numere de tip float. Să se folosească funcția qsort
// pentru a sorta aceste numere în mod crescător. Se va introduce apoi un număr x de tip float. Folosind funcția
// bsearch, să se determine dacă x există în vectorul sortat. Se pot consulta paginile de manual pentru funcțiile qsort
// și bsearch.

void p3(){
    int n;
    scanf("%d", &n);

    float *numbers = (float *)malloc(n * sizeof(float));

    // Citirea numerelor
    printf("Introduceti cele %d numere float:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Numarul %d: ", i + 1);
        scanf("%f", &numbers[i]);
    }

    // Sortare utilizand qsort
    qsort(numbers, n, sizeof(float), compare2_3);

    // Afisare vector sortat
    printf("\nVectorul sortat:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", numbers[i]);
    }
    printf("\n");

    // Cautare in vectorul sortat utilizand bsearch
    float x;
    printf("\nIntroduceti numarul float cautat ");
    scanf("%f", &x);

    float *found = (float *)bsearch(&x, numbers, n, sizeof(float), compare);

    if (found != NULL) {
        printf("%.2f a fost gasit \n", x);
    } else {
        printf("%.2f NU a fost gasit \n", x);
    }

    free(numbers);

}

// Aplicația 2.4: Să se implementeze o funcție care tabelează o funcție matematică de un parametru, primită ca
// argument. Funcția tabelată primește un parametru de tip double și returnează o valoare tot de tip double. Funcția
// de tabelare va primi ca parametri: a și b - capetele de tip double ale intervalului închis de tabelat, n - un număr
// întreg care arată în câte segmente egale se împarte intervalul [a,b], incluzând capetele acestuia și f - funcția de
// tabelat. Să se testeze funcția de tabelare cu valori a,b și n citite de la tastatură, tabelând funcțiile cos, sqrt și fabs
// din math.h
// Exemplu: tabelare(-10,10,20,fabs) va afișa pe câte o linie valori de forma f(-10)=10 f(-9)=9 … f(10)=10

void p4()
{
    double a, b;
    int n;

    printf("cap stanga interval: ");
    scanf("%lf", &a);
    printf("cap dereapta interval: ");
    scanf("%lf", &b);
    printf("numarul de segmente: ");
    scanf("%d", &n);

    printf("\n Tabelarea functiei cos: \n");
    tabulate(a, b, n, cos);

    printf("\n Tabelarea functiei sqrt: \n");
    tabulate(a, b, n, sqrt);

    printf("\n Tabelarea functiei fabs: \n");
    tabulate(a, b, n, fabs);

}
int main()
{
    p1();
    p2();
    p3();
    p4();
    return 0;
}