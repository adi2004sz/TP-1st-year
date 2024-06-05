#include <stdio.h>
#include <stdlib.h>

// Aplicația 9.10: Sa se construiasca o lista liniara simplu inlantuita care sa contina numere naturale. Sa se scrie o
// functie care sa separe elementele pare de cele impare in 2 liste separate.

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* insertEnd(Node *head, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(Node *head, FILE *fout) {
    Node *temp = head;
    while (temp != NULL) {
        fprintf(fout, "%d ", temp->data);
        temp = temp->next;
    }
    fprintf(fout, "\n");
}

void splitEvenOdd(Node *head, Node **evenList, Node **oddList) {
    Node *even = NULL;
    Node *odd = NULL;
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            even = insertEnd(even, temp->data);
        } else {
            odd = insertEnd(odd, temp->data);
        }
        temp = temp->next;
    }
    *evenList = even;
    *oddList = odd;
}

int main() {
    FILE *fin = fopen("date.in", "r");
    FILE *fout = fopen("date.out", "w");
    if (fin == NULL || fout == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    Node *list = NULL;
    int num;
    while (fscanf(fin, "%d", &num) != EOF) {
        list = insertEnd(list, num);
    }

    Node *evenList = NULL;
    Node *oddList = NULL;

    splitEvenOdd(list, &evenList, &oddList);

    fprintf(fout, "Even List: ");
    printList(evenList, fout);
    fprintf(fout, "Odd List: ");
    printList(oddList, fout);

    fclose(fin);
    fclose(fout);

    // Free memory
    while (list != NULL) {
        Node *temp = list;
        list = list->next;
        free(temp);
    }
    while (evenList != NULL) {
        Node *temp = evenList;
        evenList = evenList->next;
        free(temp);
    }
    while (oddList != NULL) {
        Node *temp = oddList;
        oddList = oddList->next;
        free(temp);
    }

    return 0;
}
