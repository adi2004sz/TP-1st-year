#include <stdio.h>

// Probleme medii
// Aplicația 4.4: Folosind câmpuri pe biți, definiţi o structură pentru memorarea următoarelor informaţii despre
// animale:
// ● numărul de picioare: număr întreg, minim 0 (ex. şarpe), maxim 1000 (ex. miriapod)
// ● greutatea în kg: număr real
// ● periculos pentru om: da/nu
// ● abrevierea ştiinţifică a speciei: şir de maxim 8 caractere
// ● vârsta maximă în ani: număr întreg, minim 0, maxim 2000
// Unde este posibil, codificaţi informaţiile prin numere întregi de dimensiune cât mai mică, spre exemplu “da”=1,
// “nu”=0. Definiţi structura în aşa fel încât să ocupe spaţiul minim de memorie posibil. Afişaţi spaţiul de memorie
// ocupat, folosind operatorul sizeof. Folosind structura definită, citiţi de la tastatură informaţii despre un animal, iar
// pe urmă afişaţi-le pe ecran.
// Exemplu: valoare=147000, unitate:gram => 147 kilogram

// Aplicația 4.5: Să se codifice următoarele informații despre un medicament, astfel încât ele să ocupe în total un
// singur octet. Să se scrie un program care să citească datele unui medicament și ulterior să le afișeze.
// ● gradul de periculozitate: scăzută, medie, mare
// ● dacă se eliberează doar pe bază de rețetă: da, nu
// ● vârsta minimă de administrare: 1...18 ani inclusiv

// Aplicația 4.6: Se consideră că o măsurătoare are asociată unitatea de măsură (gram, metru, litru) și multiplicatorul
// acesteia (pico, nano, mili, centi, deci, deca, hecto, kilo, mega, giga).
// ● Să se codifice o măsurătoare astfel încât să conțină o valoare întreagă pozitivă care să acopere un interval
// cât mai mare de valori, unitatea de măsură și multiplicatorul acesteia. O măsurătoare va ocupa exact 2
// octeți.
// ● Să se citească o valoare unsigned și o unitate de măsură. La citire nu există multiplicator. Să se determine
// multiplicatorul astfel încât valoarea stocată să fie cât mai mică, fără a se pierde precizie, iar apoi să se
// stocheze într-o măsurătoare. Dacă valoarea nu încape, se va afișa o eroare. Să se afișeze toate câmpurile
// măsurătorii.


// void aplicatiaAnimal();
// void aplicatiaMedicament();
// void aplicatiaMasuratoare();


typedef struct {
    unsigned int nrPicioare: 10;
    float greutate;
    unsigned int periculos: 1;    
    char abreviere[9];           
    unsigned int varstaMaxima: 11; 
} Animal;

void citesteAnimal(Animal *a) {
    unsigned int tempNrPicioare;
    float tempGreutate;
    unsigned int tempPericulos;
    unsigned int tempVarstaMaxima;
    
    printf("Introduceti numarul de picioare: ");
    scanf("%u", &tempNrPicioare);
    a->nrPicioare = tempNrPicioare;
    
    printf("Introduceti greutatea (kg): ");
    scanf("%f", &tempGreutate);
    a->greutate = tempGreutate;
    
    printf("Este periculos pentru om? (0 - nu, 1 - da): ");
    scanf("%u", &tempPericulos);
    a->periculos = tempPericulos;
    
    printf("Introduceti abrevierea stiintifica a speciei (max 8 caractere): ");
    scanf("%s", a->abreviere);
    
    printf("Introduceti varsta maxima in ani: ");
    scanf("%u", &tempVarstaMaxima);
    a->varstaMaxima = tempVarstaMaxima;
}


void afiseazaAnimal(const Animal *a) {
    printf("Animal:\n");
    printf("Numar de picioare: %u\n", a->nrPicioare);
    printf("Greutate: %.2f kg\n", a->greutate);
    printf("Periculos pentru om: %s\n", a->periculos ? "Da" : "Nu");
    printf("Abreviere stiintifica: %s\n", a->abreviere);
    printf("Varsta maxima: %u ani\n", a->varstaMaxima);
}

typedef struct {
    unsigned int periculozitate: 2; 
    unsigned int reteta: 1;         
    unsigned int varstaMinima: 5;   
} Medicament;

void citesteMedicament(Medicament *m) {
    unsigned int tempPericulozitate;
    unsigned int tempReteta;
    unsigned int tempVarstaMinima;
    
    printf("Introduceti gradul de periculozitate (0 - scazuta, 1 - medie, 2 - mare): ");
    scanf("%u", &tempPericulozitate);
    m->periculozitate = tempPericulozitate;
    
    printf("Se elibereaza doar pe baza de reteta? (0 - nu, 1 - da): ");
    scanf("%u", &tempReteta);
    m->reteta = tempReteta;
    
    printf("Introduceti varsta minima de administrare (1-18): ");
    scanf("%u", &tempVarstaMinima);
    m->varstaMinima = tempVarstaMinima;
}


void afiseazaMedicament(const Medicament *m) {
    printf("Medicament:\n");
    printf("Grad de periculozitate: %u\n", m->periculozitate);
    printf("Eliberare pe baza de reteta: %s\n", m->reteta ? "Da" : "Nu");
    printf("Varsta minima de administrare: %u ani\n", m->varstaMinima);
}

typedef struct {
    unsigned int valoare: 10;
    unsigned int unitateMasura: 3;
    unsigned int multiplicator: 3;
} Masuratoare;

void citesteMasuratoare(Masuratoare *m) {
    unsigned int tempValoare;
    
    printf("Introduceti valoarea măsurătorii (0-1023): ");
    scanf("%u", &tempValoare);
    m->valoare = tempValoare;
    
    m->unitateMasura = 1;
    m->multiplicator = 1;
}


void afiseazaMasuratoare(const Masuratoare *m) {
    const char *unitatiMasura[] = {"gram", "metru", "litru"};
    const char *multiplcatori[] = {"pico", "nano", "mili", "centi", "deci", "deca", "hecto", "kilo", "mega", "giga"};
    
    printf("Masuratoare:\n");
    printf("Valoare: %u\n", m->valoare);
    printf("Unitate de masura: %s\n", unitatiMasura[m->unitateMasura]);
    printf("Multiplicator: %s\n", multiplcatori[m->multiplicator]);
}


void afiseazaMeniu() {
    printf("Selectati o aplicatie:\n");
    printf("1. Informatii Animal\n");
    printf("2. Informatii Medicament\n");
    printf("3. Masuratoare\n");
    printf("0. Iesire\n");
    printf("Alegere: ");
}

int main() {
    int optiune;
    //meniu
    do {
        afiseazaMeniu();
        scanf("%d", &optiune);
        getchar(); // Consuma newline-ul ramas in buffer dupa scanf

        switch (optiune) {
            case 1: {
                Animal animal;
                printf("Aplicatia Animal\n");
                citesteAnimal(&animal);
                afiseazaAnimal(&animal);
                break;
            }
            case 2: {
                Medicament medicament;
                printf("Aplicatia Medicament\n");
                citesteMedicament(&medicament);
                afiseazaMedicament(&medicament);
                break;
            }
            case 3: {
                Masuratoare masuratoare;
                printf("Aplicatia Masuratoare\n");
                citesteMasuratoare(&masuratoare);
                afiseazaMasuratoare(&masuratoare);
                break;
            }
            case 0:
                break;
            default:
                printf("Optiune invalida. Incercati din nou.\n");
        }
    } while (optiune != 0);

    return 0;
}

