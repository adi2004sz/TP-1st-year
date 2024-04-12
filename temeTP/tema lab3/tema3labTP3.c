#include <stdio.h>

// Aplicatia 3.3 Sa se implementeze cu ajutorul unei stive functia undo dintr-un fisier text. Functia
// undo permite utilizatorului sa se revina la o versiune mai veche a documentului, eliminand ultimile
// modificari. Pentru a implementa functia undo cu o stiva fiecare modificare va fi retinuta pe stiva, iar
// cand e necesar sa se revina la o versiune anterioara se va elimina din stiva ultima modificare
// adaugata. Pe stiva se va retine la fiecare modificare: textul nou scris (sir de maxim 100 de
// caractere), randul unde a fost scris (int).

#define MAX_SIZE 100
int top = -1;
char stack[MAX_SIZE][100]; // Stiva textului
int lines[MAX_SIZE]; // Stiva numarului liniei

void push(char *text, int line) {
    if (top == MAX_SIZE - 1) {
        printf("Stiva plina\n");
        return;
    }
    strcpy(stack[++top], text);
    lines[top] = line;
}

void undo() {
    if (top == -1) {
        printf("Nu exista modificari pentru a face undo\n");
        return;
    }
    printf("Undo pentru linia %d: %s\n", lines[top], stack[top]);
    top--;
}

int main() {
    push("Text modificat", 10); // Exemplu modificare
    undo(); // la ultima modificare
    return 0;
}
