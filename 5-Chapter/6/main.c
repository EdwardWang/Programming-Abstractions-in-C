#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ListSubsets(char *set);

int main(int argc, char *argv)
{
	ListSubsets("ABCD");
	return 0;
}

static void listsubsets(char *element,char *subset)
{
	if (*subset == 0) {
		printf("{%s}\n", element);
	} else {
		int i;
		char *tmpset = subset;
		for (i = 0;i <= strlen(subset);i++,tmpset++) {
			char buf[10];
			memset(buf,0,10);
			strcpy(buf,element);
			buf[strlen(buf)] = *tmpset;
			buf[strlen(buf)] = 0;
			if (*tmpset == 0) {
				listsubsets(buf, tmpset);
			} else {
				listsubsets(buf, tmpset+1);
			}
			
		}
	}
}

void ListSubsets(char *set)
{
	char buf[10];
	memset(buf,0,10);
	listsubsets(buf,set);
}
