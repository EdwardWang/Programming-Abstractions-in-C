#include <stdio.h>

int NHanoiMoves(int n);

int main(int argc, char *argv[])
{
	int steps = NHanoiMoves(3);
	printf("%d\n", steps);
}

int NHanoiMoves(int n)
{
	int sum = 0;
	if (n == 1) {return 1;}
	else {
		sum += NHanoiMoves(n-1);
		sum += 1;
		sum += NHanoiMoves(n-1);
		return sum;
	}
}
