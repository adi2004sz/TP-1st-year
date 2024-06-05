#include <stdio.h>
#include <stdlib.h>

// Aplicația 9.9: Sa se construiasca o lista liniara simplu inlantuita cu elemente numere intregi. Sa se stearga din
// lista elementele pare.

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

Node* removeEven(Node *head) {
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL) {
        if (curr->data % 2 == 0) {
            Node *temp = curr;
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            curr = curr->next;
            free(temp);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
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

    fprintf(fout, "List: ");
    printList(list, fout);

    list = removeEven(list);

    fprintf(fout, "List after removing : ");
    printList(list, fout);

    fclose(fin);
    fclose(fout);

    while (list != NULL) {
        Node *temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}
