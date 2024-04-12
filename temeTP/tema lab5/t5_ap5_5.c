#include <stdio.h>
#include <stdlib.h>

//Aplicația 5.5: Să se scrie un program similar cu hexdump, care primește un nume de fișier în linia de comandă, 
// citește câte 16 octeți din el și îi afișează pe câte o linie. 
//Fiecare linie începe cu offsetul ei în fișier, afișat în hexazecimal pe 8 cifre cu 0 în față, 
// după care valorile hexa ale celor 16 octeți pe câte 2 cifre și în final caracterele. 
//Dacă codul unui caracter este în intervalul 32-255 se va afișa ca atare, altfel se va
// afișa un punct în locul său. Dacă ultima linie este incompletă, se va completa cu octeți de 0.


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Utilizare: %s nume_fisier\n", argv[0]);
        return 1;
    }

    FILE *fisier = fopen(argv[1], "rb");
    if (!fisier) {
        perror("Eroare la deschiderea fisierului");
        return 2;
    }

    unsigned char buf[16];
    int cnt, i;
    long offset = 0;

    while ((cnt = fread(buf, 1, 16, fisier)) > 0) {
        printf("%08lx ", offset);

        for (i = 0; i < cnt; ++i) {
            printf("%02x ", buf[i]);
        }
        for (i = cnt; i < 16; ++i) {
            printf("   ");
        }

        printf(" |");
        for (i = 0; i < cnt; ++i) {
            if (buf[i] >= 32 && buf[i] <= 255) {
                printf("%c", buf[i]);
            } else {
                printf(".");
            }
        }
        printf("|\n");
        offset += 16;
    }

    fclose(fisier);

    return 0;
}
