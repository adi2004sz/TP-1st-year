#include <stdio.h>

// Aplicația 10.4: Sa se determine recursiv al n-lea termen Fibonacci.


int fib(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

void p4(void)
{
    printf("%d\n", fib(4));
}

int main(void)
{
    p4();
    return 0;
}
