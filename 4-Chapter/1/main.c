#include <stdio.h>

int Cannonball(int n);

int main(int argc, char *argv[])
{
    printf("%d\n", Cannonball(3));
}

int Cannonball(int n)
{
    if (n == 1) return 1;
    else {
        return (Cannonball(n-1) + n*n);
    }
}
