#include <stdio.h>

int Fib(int n);
int main(int argc, char *argv[])
{
    printf("%d\n", Fib(5));
    return 0;
}

int Fib(int n)
{
    int a1 = 0;int a2 = 1;
    int result = n;int i;
    if (n == 1) return a1;
    if (n == 2) return a2;
    for (i = 2; i < n; i++) {
        result = a1+a2;
        a1 = a2;
        a2 = result;
    }
    return result;
}
