#include <stdio.h>
#include <math.h>

// Problema 11.2 Divide et Impera

void p2(void)
{
    int n, i;
    double ma, mb, m, d, G = 667400000000, pas, x = 0.0, Fa, Fb;
    scanf("%d %lf %lf %lf %lf", &n, &ma, &mb, &m, &d);

    pas = d / n;

    for (i = 0; i <= n; i++)
    {
        Fa = G * ma * m / (x * x);
        Fb = G * mb * m / ((d - x) * (d - x));
        printf("%lf %lf %lf\n", x, Fa, Fb);
        x += pas;
    }
}

int main(void)
{
    p2();
    return 0;
}
