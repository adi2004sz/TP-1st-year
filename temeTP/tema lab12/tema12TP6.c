#include <stdio.h>

#define MAX 100


int c, b, g, a;
char entitati[5][100] = {"", "casa", "bloc", "gradina", "atelier"};
int ans[MAX];

int verificare6(int p) {
    if (p != 1) {
        switch (ans[p]) {
            case 1:
                if (ans[p - 1] == 1 || ans[p - 1] == 2 || ans[p - 1] == 3) {
                    return 1;
                }
                break;
            case 2:
                if (ans[p - 1] == 1 || ans[p - 1] == 2) {
                    return 1;
                }
                break;
            case 3:
                if (ans[p - 1] == 1 || ans[p - 1] == 3 || ans[p - 1] == 4) {
                    return 1;
                }
                break;
            case 4:
                if (ans[p - 1] == 3 || ans[p - 1] == 4) {
                    return 1;
                }
                break;
        }
    } else {
        return 1;
    }
    return 0;
}

int solutie6(int p) {
    int i, countC = 0, countB = 0, countG = 0, countA = 0;
    for (i = 1; i <= p; i++) {
        switch (ans[i]) {
            case 1: countC++; break;
            case 2: countB++; break;
            case 3: countG++; break;
            case 4: countA++; break;
        }
    }
    return (c == countC && b == countB && g == countG && a == countA);
}

void afisare6(void) {
    int i;
    for (i = 1; i <= c + b + g + a; i++) {
        printf("%s ", entitati[ans[i]]);
    }
    printf("\n");
}

void back6(int p) {
    if (p > c + b + g + a) {
        return;
    }
    int i;
    for (i = 1; i <= 4; i++) {
        ans[p] = i;
        if (verificare6(p)) {
            if (solutie6(p)) {
                afisare6();
            } else {
                back6(p + 1);
            }
        }
    }
}

void p6(void) {
    c = 2;
    b = 1;
    g = 1;
    a = 1;
    back6(1);
}