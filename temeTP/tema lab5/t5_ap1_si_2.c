#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Aplicația 5.1: Modificați exemplul anterior, astfel încât să se scrie la început de fișier numărul de produse din baza de date.

void scriere_modificata_pentru_5_1() {
    FILE *fis;

    if ((fis = fopen("produse.dat", "wb")) == NULL) {
        printf("nu se poate deschide fisierul\n");
        exit(EXIT_FAILURE);
    }

    fwrite(&nProduse, sizeof(int), 1, fis);

    fwrite(produse, sizeof(Produs), nProduse, fis);

    fclose(fis);
}

// Aplicația 5.2: Scrieți un program care copiază conținutul unui fișier sursă într-un fișier destinație. 
// Numele fișierelor se citesc din linia de comandă. Pentru eficiența copierii, programul va citi câte un bloc de maxim 4096 de octeți,
//  pe care îl va scrie în destinație.
// Exemplu: ./copiere src.dat dst.dat                    -> copiază src.dat în dst.dat

#define BUFFER_SIZE 4096

Produs produse[1000];
int nProduse;

typedef struct{
    char *nume;
    float pret;
    }Produs;

void scriere_modificata_pentru_5_1()
{
    FILE *fis;

    if((fis=fopen("produse.dat","wb"))==NULL){
        printf("nu se poate deschide fisierul\n");
        exit(EXIT_FAILURE);
    }
    fwrite(&nProduse, sizeof(int), 1, fis);
    
    fwrite(produse, sizeof(Produs), nProduse, fis);
    fclose(fis);
}


int main(int argc, char *argv[])
{
    //Aplicatia 5.2
    FILE *fin, *fout;   
    char buffer[BUFFER_SIZE];  
    size_t bytesRead;

    if(argc != 3) {
        fprintf(stderr, "Utilizare: %s <fisier sursa> <fisier destinatie>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    
    fin = fopen(argv[1], "rb");
    if(fin == NULL) {
        fprintf(stderr, "Eroare la deschiderea fisierului sursa %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    
    fout = fopen(argv[2], "wb");
    if(fout == NULL) {
        fprintf(stderr, "Eroare la deschiderea fisierului destinatie %s\n", argv[2]);
        fclose(fin); 
        exit(EXIT_FAILURE);
    }

    while((bytesRead = fread(buffer, 1, BUFFER_SIZE, fin)) > 0) {
        fwrite(buffer, 1, bytesRead, fout);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
