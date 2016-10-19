#include <stdio.h>

int GCD(int x, int y);

int main(int argc, char *argv[])
{
    printf("%d\n", GCD(27,3));
    return 0;
}

int GCD(int x, int y)
{
    if ( x % y == 0) return y;
    else
        return GCD(y%y,x%y);
}
