#include <stdio.h>

#define MAX 100

int n, k;
int ans[MAX];

int verificare1(int p) {
    if (ans[p] == 0) {
        return 0;
    } else {
        return 1;
    }
}

int solutie1(int p) {
    int count = 0, i;
    for (i = 0; i <= p; i++) {
        if (ans[i] == 1) {
            count++;
        }
    }
    return (p == n - 1 && count == k);
}

void afisare1(void) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", ans[i]);
    }
    printf("\n");
}

void back1(int p) {
    int i;
    if (p == n) {
        return;
    }
    for (i = 0; i <= 9; i++) {
        ans[p] = i;
        if (verificare1(p)) {
            if (solutie1(p)) {
                afisare1();
            } else {
                back1(p + 1);
            }
        }
    }
}

void p1(void) {
    n = 3;
    k = 2;
    back1(0);
}
