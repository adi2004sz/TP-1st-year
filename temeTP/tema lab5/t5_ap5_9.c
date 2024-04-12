#include <stdio.h>
#include <stdlib.h>

// Aplicația 5.9: Să se scrie un program care primește o serie de n programe în linia de comandă și le concatenează pe 
// primele n-1 într-un nou fișier având numele specificat pe ultima poziție din linia de comandă.
// Exemplu: ./concat 1.dat 2.dat 3.dat rez.dat       -> concatenează conținutul fișierelor {1.dat, 2.dat, 3.dat} într-un 
// nou fișier, denumit rez.dat

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Utilizare: %s fisier1 fisier2 ... fisier_n rezultat\n", argv[0]);
        return 1;
    }

    FILE *rezultat = fopen(argv[argc - 1], "wb");
    if (!rezultat) {
        perror("Eroare la crearea fisierului rezultat");
        return 2;
    }

    for (int i = 1; i < argc - 1; ++i) {
        FILE *fisier = fopen(argv[i], "rb");
        if (!fisier) {
            perror("Eroare la deschiderea fisierului de intrare");
            fclose(rezultat);
            return 3;
        }

        unsigned char buffer[1024];
        size_t bytes_read;
        while ((bytes_read = fread(buffer, 1, sizeof(buffer), fisier)) > 0) {
            if (fwrite(buffer, 1, bytes_read, rezultat) != bytes_read) {
                perror("Eroare la scrierea in fisierul rezultat");
                fclose(fisier);
                fclose(rezultat);
                return 4;
            }
        }

        fclose(fisier);
    }

    fclose(rezultat);

    printf("Fisierul rezultat \"%s\" a fost creat cu succes!\n", argv[argc - 1]);
    return 0;
}
