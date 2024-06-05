#include <stdio.h>

#define MAX 100


char culori[7][100] = {" ", "alb", "galben", "rosu", "verde", "albastru", "negru"};
int ans[MAX];

int verificare4(int p) {
    int i;
    for (i = 1; i < p; i++) {
        if (ans[i] == ans[p]) {
            return 0;
        }
    }
    return 1;
}

int solutie4(int p) {
    if (p == 3 && (ans[2] == 4 || ans[2] == 2)) {
        return 1;
    }
    return 0;
}

void afisare4() {
    int i;
    for (i = 1; i <= 3; i++) {
        printf("%s ", culori[ans[i]]);
    }
    printf("\n");
}

void back4(int p) {
    int i;
    for (i = 1; i <= 6; i++) {
        ans[p] = i;
        if (verificare4(p)) {
            if (solutie4(p)) {
                afisare4();
            } else {
                back4(p + 1);
            }
        }
    }
}

void p4(void) {
    back4(1);
}
