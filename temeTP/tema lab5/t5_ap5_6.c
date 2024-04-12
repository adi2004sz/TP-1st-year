#include <stdio.h>
#include <stdlib.h>

// Aplicația 5.6: Să se scrie un program care primește 2 fișiere în linia de comandă și le compară între ele.
//  Pentru fiecare octet diferit găsit, se afișează offsetul acestuia și valorile sale din fiecare fișier, în hexazecimal,
//   pe câte 2 cifre. Dacă fișierele sunt de dimensiuni diferite, în final se vor afișa toți octeții din fișierul mai mare. 
// Dacă fișierele sunt identice, programul nu va afișa nimic.

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Utilizare: %s fisier1 fisier2\n", argv[0]);
        return 1;
    }

    FILE *fisier1 = fopen(argv[1], "rb");
    if (!fisier1) {
        perror("Eroare la deschiderea primului fisier");
        return 2;
    }

    FILE *fisier2 = fopen(argv[2], "rb");
    if (!fisier2) {
        perror("Eroare la deschiderea celui de-al doilea fisier");
        fclose(fisier1);
        return 3;
    }

    int ch1, ch2;
    long offset = 0;

    while (1) {
        ch1 = fgetc(fisier1);
        ch2 = fgetc(fisier2);

        if (ch1 == EOF || ch2 == EOF)
            break;

        if (ch1 != ch2) {
            printf("Diferenta la offsetul 0x%lx: 0x%02x vs 0x%02x\n", offset, ch1, ch2);
        }

        offset++;
    }

    if (ch1 != EOF || ch2 != EOF) {
        FILE *fisierLung = (ch1 != EOF) ? fisier1 : fisier2;
        int ch = (ch1 != EOF) ? ch1 : ch2;

        do {
            if (ch != EOF) {
                printf("Extra la offsetul 0x%lx: 0x%02x\n", offset, ch);
            }
            ch = fgetc(fisierLung);
            offset++;
        } while (ch != EOF);
    }

    fclose(fisier1);
    fclose(fisier2);

    return 0;
}
