#include <stdio.h>

#define MAX 100

float volume[MAX] = {0.0, 1.23, 3.47, 0.89, 4.12, 2.36, 4.78, 1.56, 3.09, 0.45, 2.78, 4.33, 1.98, 3.67, 0.11, 2.45, 3.79, 4.56, 0.67, 2.88, 3.21};
float volum;
int n;
int ans[MAX];

int verificare5(int p) {
    int i;
    for (i = 1; i < p; i++) {
        if (ans[i] == ans[p]) {
            return 0;
        }
    }
    return 1;
}

int solutie5(int p) {
    int i;
    float suma = 0.0;
    for (i = 1; i <= p; i++) {
        suma = suma + volume[ans[i]];
    }
    return suma <= volum;
}

void afisare5(int p) {
    int i;
    for (i = 1; i <= p; i++) {
        printf("%f ", volume[ans[i]]);
    }
    printf("\n");
}

void back5(int p) {
    int i;
    for (i = 1; i <= n; i++) {
        ans[p] = i;
        if (verificare5(p)) {
            if (solutie5(p)) {
                afisare5(p);
            }
            back5(p + 1);
        }
    }
}

void p5(void) {
    n = 5;
    volum = 6.6;
    back5(1);
}
