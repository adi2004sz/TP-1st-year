#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aplicația 5.8: Să se scrie un program care primește în linia de comandă un nume de fișier și o serie de octeți, 
// dați în hexazecimal. Programul va afișa toate pozițiile din fișier la care se află secvența de octeți specificați.
// Exemplu: ./cautare 1.dat 01 aa b2 45        -> caută în fișierul 1.dat secvența {01, aa, b2, 45} și afișează toate
//  pozițiile la care o găsește

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Utilizare: %s nume_fisier octet1 [octet2 ...]\n", argv[0]);
        return 1;
    }

    const char *nume_fisier = argv[1];

    FILE *fisier = fopen(nume_fisier, "rb");
    if (!fisier) {
        perror("Eroare la deschiderea fisierului");
        return 2;
    }

    int lungime_secventa = argc - 2;
    unsigned char secventa[lungime_secventa];

    for (int i = 0; i < lungime_secventa; ++i) {
        sscanf(argv[i + 2], "%hhx", &secventa[i]);
    }

    int offset = 0;
    int gasit = 0;
    int nr_aparitii = 0;

    while (1) {
        unsigned char buffer[lungime_secventa];
        size_t bytes_read = fread(buffer, sizeof(unsigned char), lungime_secventa, fisier);
        if (bytes_read != lungime_secventa) {
            break;
        }

        if (memcmp(buffer, secventa, lungime_secventa) == 0) {
            if (!gasit) {
                printf("Secventa a fost gasita la pozitiile:\n");
                gasit = 1;
            }
            printf("%d\n", offset);
            nr_aparitii++;
        }

        offset++;
    }

    fclose(fisier);

    if (!gasit) {
        printf("Secventa nu a fost gasita in fisier.\n");
    } else {
        printf("Numarul total de aparitii: %d\n", nr_aparitii);
    }

    return 0;
}
