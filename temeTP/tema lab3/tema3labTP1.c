#include <stdio.h>

// Aplicatia 3.1 Implementati pe calculator structura de date stiva, asa cum este descrisa in laborator

#define MAX_SIZE 100
int top = -1;
int stack[MAX_SIZE];

void push(int item) {
    if (top == MAX_SIZE - 1) {
        printf("Stiva plina\n");
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stiva goala\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if (top == -1) {
        printf("Stiva goala\n");
        return;
    }
    printf("Elementele din stiva sunt: ");
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Elementul extras din stiva: %d\n", pop());
    display();
    return 0;
}
