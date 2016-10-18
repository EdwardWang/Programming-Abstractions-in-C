#include <stdio.h>

static int n0 = 0;
static int n1 = 0;

void move_tower(int n, char start, char finish, char tmp);
void move_tower_0(int n, char start, char finish, char tmp);

int main(int argc, char *argv[])
{
	move_tower(3, 'A', 'B', 'C');
	printf("---------------------------------\n");
	move_tower_0(3, 'A', 'B', 'C');

	printf("1 func counts: %d, 0 func counts: %d\n", n1, n0);
	return 0;
}

static void move_single_disk(char start, char finish)
{
	printf("%c---->%c\n", start,finish);
}

void move_tower(int n, char start, char finish, char tmp)
{
	n1++;
	if (n == 1) {
		move_single_disk(start,finish);
	} else {
		move_tower(n-1, start, tmp, finish);
		move_single_disk(start,finish);
		move_tower(n-1, tmp, finish, start);
	}
}

void move_tower_0(int n, char start, char finish, char tmp)
{
	n0++;
	if (n == 0) { return; }
	else {
		move_tower_0(n-1, start, tmp, finish);
		move_single_disk(start,finish);
		move_tower_0(n-1, tmp, finish, start);
	}
}
