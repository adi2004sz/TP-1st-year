#include <stdio.h>

// Aplicatia 3.4 Sa se implementeze cu ajutorul unei cozi un buffer care retine temporar informatiile
// primite de la diversi transmitatori (informatia este adaugata in coada) si le transmite mai apoi catre
// un receptor (informatia este eliminata din coada). Informatia primita in buffer are urmatoare
// structura: numar identificare transmitator (int), mesaj (sir de caractere de maxim 256 caractere).

#define MAX_SIZE 100
int front = -1, rear = -1;
struct Message {
    int transmitterId;
    char message[256];
} queue[MAX_SIZE];

void enqueue(int transmitterId, char *message) {
    if (rear == MAX_SIZE - 1) {
        printf("Coada plina\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear].transmitterId = transmitterId;
    strcpy(queue[rear].message, message);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Coada goala\n");
        return;
    }
    printf("Transmitator: %d - Mesaj: %s\n", queue[front].transmitterId, queue[front].message);
    front++;
}

int main() {
    enqueue(1, "Mesaj 1 de la transmitatorul 1");
    enqueue(2, "Mesaj 1 de la transmitatorul 2");
    enqueue(1, "Mesaj 2 de la transmitatorul 1");
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
