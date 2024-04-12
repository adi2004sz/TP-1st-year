#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nume[21];
    float nota;
} Student;

typedef struct {
    char nume[16]; // + '\0'
    unsigned int dimensiune: 10; // Max 1024
    unsigned int tip: 2; // 3 valori posibile
    unsigned int tipAcces: 1; // 2 valori posibile
} Fisier;

#define MAX_FISIERE 10

// void curataBufferStdin();
// void aplicatia40();
// void aplicatia41();
// Fisier* citesteFisiereDinamic(int *nrFisiere);
// void aplicatia42(Fisier *fisiere, int nrFisiere);
// void aplicatia43(Fisier *fisiere, int nrFisiere);
// void elibereazaMemorieFisiere(Fisier *fisiere);


void curataBufferStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Aplicația 4.0: Să se creeze o structură care reține următoarele informații despre un student: nume (maxim 20 de
// caractere), nota. Să se citească un element din structură și să se afișeze pe ecran.

void aplicatia40() {
    Student s;
    printf("Introduceti numele studentului: ");
    scanf("%20s", s.nume);
    printf("Introduceti nota studentului: ");
    scanf("%f", &s.nota);
    printf("Student: %s, Nota: %.2f\n", s.nume, s.nota);
}

// Aplicația 4.1: Să se codifice cu ajutorul structurilor cu câmpuri pe biți informațiile despre un fișier: nume (șir de
// maxim 15 caractere), dimensiunea acestuia (int - număr de octeți, maxim 1024 octeți), tipul acestuia (.txt - 0, .doc
// - 1, .xls – 2), tipul fisierului (normal – 0, read-only – 1). Să se citească informația despre un fișier, și să se afișeze
// pe ecran.

void aplicatia41() {
    Fisier f;
    printf("Numele fisierului (maxim 15 caractere): ");
    fgets(f.nume, sizeof(f.nume), stdin);
    f.nume[strcspn(f.nume, "\n")] = '\0'; // Eliminam newline

    unsigned int tempDimensiune;
    printf("Dimensiunea fisierului (maxim 1024 octeti): ");
    scanf("%u", &tempDimensiune);
    f.dimensiune = tempDimensiune;
    curataBufferStdin();

    unsigned int tempTip;
    printf("Tipul fisierului (.txt - 0, .doc - 1, .xls - 2): ");
    scanf("%u", &tempTip);
    f.tip = tempTip;
    curataBufferStdin();

    unsigned int tempTipAcces;
    printf("Tipul fisierului (normal - 0, read-only - 1): ");
    scanf("%u", &tempTipAcces);
    f.tipAcces = tempTipAcces;
    curataBufferStdin();

    printf("Fisier: %s, Dimensiune: %u, Tip: %u, Tip Acces: %u\n", f.nume, f.dimensiune, f.tip, f.tipAcces);
}



Fisier* citesteFisiereDinamic(int *nrFisiere) {
    int tempNrFisiere;
    
    printf("Introduceti numarul de fisiere: ");
    scanf("%d", &tempNrFisiere);
    curataBufferStdin();

    Fisier *fisiere = (Fisier*)malloc(tempNrFisiere * sizeof(Fisier));
    if (!fisiere) {
        printf("Eroare la memorie\n");
        *nrFisiere = 0;
        return NULL;
    }

    for (int i = 0; i < tempNrFisiere; i++) {
        printf("\nFisier %d:\n", i + 1);
        printf("Numele fisierului (maxim 15 caractere): ");
        fgets(fisiere[i].nume, sizeof(fisiere[i].nume), stdin);
        fisiere[i].nume[strcspn(fisiere[i].nume, "\n")] = '\0'; // Eliminam newline

        unsigned int tempDimensiune;
        printf("Dimensiunea fisierului (maxim 1024 octeti): ");
        scanf("%u", &tempDimensiune);
        fisiere[i].dimensiune = tempDimensiune;
        curataBufferStdin();

        unsigned int tempTip;
        printf("Tipul fisierului (.txt - 0, .doc - 1, .xls - 2): ");
        scanf("%u", &tempTip);
        fisiere[i].tip = tempTip;
        curataBufferStdin();

        unsigned int tempTipAcces;
        printf("Tipul fisierului (normal - 0, read-only - 1): ");
        scanf("%u", &tempTipAcces);
        fisiere[i].tipAcces = tempTipAcces;
        curataBufferStdin();
    }

    *nrFisiere = tempNrFisiere;
    return fisiere;
}



// Aplicația 4.2: Cu ajutorul structurii de la problema mai sus să se salveze într-un vector de structuri declarat static
// informații despre mai multe fișiere (maxim 10). Să se citească de la tastatură informațiile despre fișiere și să se
// salveze în fișierul memorie.txt.

void aplicatia42(Fisier *fisiere, int nrFisiere) {
    FILE *fp = fopen("memorie.txt", "w");
    if (fp != NULL) {
        for (int i = 0; i < nrFisiere; i++) {
            fprintf(fp, "%s %u %u %u\n", fisiere[i].nume, fisiere[i].dimensiune, fisiere[i].tip, fisiere[i].tipAcces);
        }
        fclose(fp);
        printf("Informatiile au fost salvate cu succes in 'memorie.txt'.\n");
    } else {
        printf("Eroare la deschiderea fisierului 'memorie.txt'.\n");
    }
}

// Aplicația 4.3: Modificați problema de mai sus astfel încât vectorul de structuri să fie alocat dinamic.

void aplicatia43(Fisier *fisiere, int nrFisiere) {
    //vezi main
    aplicatia42(fisiere, nrFisiere);
}

void elibereazaMemorieFisiere(Fisier *fisiere) {
    free(fisiere);
}

int main() {
    int optiune, nrFisiere;
    Fisier *fisiere = NULL;
    //meniu
    while (1) {
        printf("\nMeniu Principal\n");
        printf("1. Aplicatia 4.0\n");
        printf("2. Aplicatia 4.1\n");
        printf("3. Aplicatia 4.2\n");
        printf("4. Aplicatia 4.3\n");
        printf("5. Iesire\n");
        printf("Selectati o optiune: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                aplicatia40();
                break;
            case 2:
                aplicatia41();
                break;
            case 3:
                fisiere = citesteFisiereDinamic(&nrFisiere);
                aplicatia42(fisiere, nrFisiere);
                break;
            case 4:
                if (fisiere != NULL) {
                    aplicatia43(fisiere, nrFisiere);
                    elibereazaMemorieFisiere(fisiere);
                    fisiere = NULL;
                } else {
                    printf("Niciun fisier citit. Executati mai intai aplicatia 4.2.\n");
                }
                break;
            case 5:
                return 0;
            default:
                printf("Optiune invalida.\n");
        }
    }

    return 0;
}