#include <stdio.h>

int RaiseIntToPower(int n, int k);

int main(int argc, char *argv[])
{
    printf("%d\n", RaiseIntToPower(10,3));
    return 0;
}

int RaiseIntToPower(int n, int k)
{
    if (k == 0) { return 1;}
    else {
        return RaiseIntToPower(n,k-1) * n;
    }
}

