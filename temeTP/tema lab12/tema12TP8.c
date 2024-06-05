#include <stdio.h>

#define MAX 100

int lungime, n;
int ans[MAX];

int verificare8(int p) {
    int i;
    for (i = 1; i < p; i++) {
        if (ans[i] >= ans[p]) {
            return 0;
        }
    }
    return 1;
}

int solutie8(int p) {
    int i, suma = 0;
    for (i = 1; i <= p; i++) {
        suma = suma + ans[i];
    }
    return (suma == lungime) && (p == n);
}

void afisare8(void) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

void back8(int p) {
    int i;
    for (i = 1; i <= lungime; i++) {
        ans[p] = i;
        if (verificare8(p)) {
            if (solutie8(p)) {
                afisare8();
            } else {
                back8(p + 1);
            }
        }
    }
}

void p8(void) {
    lungime = 20;
    n = 3;
    back8(1);
}

int main(void) {
    p8();
    return 0;
}
