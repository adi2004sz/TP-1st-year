#include <stdio.h>

#define MAX 100


int n;
int ans[MAX];

int verificare2(int p) {
    int i;
    for (i = 1; i < p; i++) {
        if (ans[i] == ans[p]) {
            return 0;
        }
    }
    return 1;
}

int solutie2(int p) {
    int mijloc, i, j;
    if (p == n) {
        mijloc = n / 2 + n % 2;
        for (i = 1; i < mijloc; i++) {
            for (j = i + 1; j <= mijloc; j++) {
                if (ans[i] < ans[j]) {
                    return 0;
                }
            }
        }
        for (i = mijloc; i < n; i++) {
            for (j = i + 1; j <= n; j++) {
                if (ans[i] > ans[j]) {
                    return 0;
                }
            }
        }
        return 1;
    } else {
        return 0;
    }
}

void afisare2(void) {
    int i;
    for (i = 1; i <= n; i++) {
        printf("%d", ans[i]);
    }
    printf("\n");
}

void back2(int p) {
    int i;
    for (i = 1; i <= n; i++) {
        ans[p] = i;
        if (verificare2(p)) {
            if (solutie2(p)) {
                afisare2();
            } else {
                back2(p + 1);
            }
        }
    }
}

void p2(void) {
    n = 5;
    back2(1);
}
