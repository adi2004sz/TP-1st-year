#include <stdio.h>
#include <stdlib.h>

// Aplicația 5.7: Un program primește în linia de comandă un nume de fișier, un offset dat în hexazecimal și apoi o serie de octeți, 
// specificați tot în hexazecimal. Programul va scrie în fișierul specificat, începând de la offsetul dat toți octeții primiți în linia
//  de comandă. Restul fișierului va rămâne nemodificat.
// Exemplu: ./inlocuire 1.dat 4a0f 9e b0 51          -> scrie octeții {9e, b0, 51} în fișierul 1.dat, începând cu poziția 4a0f


int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Utilizare: %s nume_fisier offset_hex octet1 [octet2 ...]\n", argv[0]);
        return 1;
    }

    const char *nume_fisier = argv[1];
    long offset = strtol(argv[2], NULL, 16);

    FILE *fisier = fopen(nume_fisier, "r+b");
    if (!fisier) {
        fisier = fopen(nume_fisier, "w+b");
        if (!fisier) {
            perror("Nu s-a putut deschide sau crea fisierul");
            return 2;
        }
    }

    if (fseek(fisier, offset, SEEK_SET) != 0) {
        perror("Eroare la mutarea in fisier");
        fclose(fisier);
        return 3;
    }

    for (int i = 3; i < argc; ++i) {
        unsigned int octet;
        if (sscanf(argv[i], "%x", &octet) == 1) {
            unsigned char val = octet;
            if (fwrite(&val, sizeof(val), 1, fisier) != 1) {
                perror("Eroare la scrierea în fisier");
                fclose(fisier);
                return 4;
            }
        } else {
            printf("Octetul '%s' nu este valid.\n", argv[i]);
        }
    }

    fclose(fisier);
    return 0;
}
