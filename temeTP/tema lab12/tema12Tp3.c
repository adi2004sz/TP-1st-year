#include <stdio.h>

#define MAX 100

int numV[MAX], len, max, n, k;
int ans[MAX];

void descompunere(int nr) {
    int aux = nr, count = 0;
    len = 0;
    while (aux) {
        count++;
        aux = aux / 10;
    }
    while (nr) {
        numV[count - len] = nr % 10;
        len++;
        nr = nr / 10;
    }
}

int verificare3(int p) {
    int i;
    for (i = 1; i < p; i++) {
        if (ans[i] >= ans[p]) {
            return 0;
        }
    }
    return 1;
}

int solutie3(int p) {
    if (p == (len - k)) {
        return 1;
    } else {
        return 0;
    }
}

int numar(void) {
    int i, numar = 0;
    for (i = 1; i <= (len - k); i++) {
        numar = numar * 10 + numV[ans[i]];
    }
    return numar;
}

void back3(int p) {
    int i, aux;
    for (i = 1; i <= len; i++) {
        ans[p] = i;
        if (verificare3(p)) {
            if (solutie3(p)) {
                aux = numar();
                if (aux > max) {
                    max = aux;
                }
            } else {
                back3(p + 1);
            }
        }
    }
}

void p3(void) {
    n = 3452234;
    k = 4;
    descompunere(n);
    back3(1);
    printf("%d\n", max);
}
