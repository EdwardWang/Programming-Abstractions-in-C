#include <stdio.h>

int C(int n, int k);

int main(int argc, char *argv[])
{
    printf("%d\n", C(6,2));
    return 0;
}

int C(int n, int k)
{
    if (k == 0 || n == k) {
        return 1;
    } else {
        return C(n-1,k-1) + C(n-1,k);
    }
}
