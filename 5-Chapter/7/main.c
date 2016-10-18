#include <stdio.h>
#include <string.h>

static char s[] = "01";

void GenerateBinaryCode(int nBits);

int main(int agc, char *argv[])
{
	GenerateBinaryCode(3);
	return 0;
}

static void list2calc(char *prefix, int n)
{
	if (n == 0) {
		printf("%s\n", prefix);
	} else {
		int i;
		char *str = strdup(s);
		for (i = 0; i < strlen(str);i++) {
			char buf[10];
			memset(buf,0,10);
			strcpy(buf,prefix);
			buf[strlen(buf)] = str[i];
			buf[strlen(buf)] = 0;
			list2calc(buf, n-1);
		}
		free(str);
	}
}

void GenerateBinaryCode(int nBits)
{
	list2calc("", nBits);
}
