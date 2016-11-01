#include <stdio.h>

int DigitSum(int n);
int main(int argc, char *argv[])
{
    printf("%d\n", DigitSum(1928));
    printf("%d\n", DigitSum(3428));
    return 0;
}

int DigitSum(int n)
{
    if (n == 0) {
        return 0;
    } else {
        return (DigitSum(n/10) + n % 10);
    }
}
