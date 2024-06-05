#include <stdio.h>

#define MAX 100

int laturi[100] = {0, 1, 2, 2, 1}, latura;
int ans[MAX], n, k;

int verificare7(int p) {
    int i;
    for (i = 1; i < p; i++) {
        if (ans[i] == ans[p]) {
            return 0;
        }
    }
    return 1;
}

int solutie7(int p) {
    int arieMare = 0, arieSolutie = 0, i;
    arieMare = latura * latura;
    for (i = 1; i <= p; i++) {
        arieSolutie = arieSolutie + ans[i] * ans[i];
    }
    return (arieSolutie <= arieMare) && (p == n);
}

void back7(int p) {
    int i;
    for (i = 1; i <= n; i++) {
        ans[p] = i;
        if (verificare7(p)) {
            if (solutie7(p)) {
                k = 1;
            } else {
                back7(p + 1);
            }
        }
    }
}

void p7(void) {
    n = 4;
    k = 0;
    latura = 4;
    back7(1);
    if (k == 1) {
        printf("Exista configuratie\n");
    } else {
        printf("Nu exista configuratie\n");
    }
}

int main(void) {
    p7();
    return 0;
}