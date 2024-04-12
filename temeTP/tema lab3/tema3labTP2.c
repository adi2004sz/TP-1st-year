#include <stdio.h>

// Aplicatia 3.2 Implementati pe calculator structura de date coada, asa cum este descrisa in
// laborator.

#define MAX_SIZE 100
int front = -1, rear = -1;
int queue[MAX_SIZE];

void enqueue(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Coada plina\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = item;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Coada goala\n");
        return -1;
    }
    return queue[front++];
}

void display() {
    if (front == -1 || front > rear) {
        printf("Coada goala\n");
        return;
    }
    printf("Elementele din coada sunt: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Elementul extras din coada: %d\n", dequeue());
    display();
    return 0;
}
