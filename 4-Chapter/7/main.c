#include <stdio.h>

int DigitRoot(int n);

int main(int argc, char *argv[])
{
    printf("%d\n", DigitRoot(1729));
    return 0;
}

int DigitSum(int n)
{
    if (n == 0) {
        return 0;
    } else {
        return (DigitSum(n/10) + n%10);
    }
}

int DigitRoot(int n)
{
    if (n / 10 == 0)
        return n;
    else {
        int sum;
        sum = DigitSum(n);
        return DigitRoot(sum);
    }
}
