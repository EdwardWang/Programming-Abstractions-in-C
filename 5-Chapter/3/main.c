#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ListPermutations(char *str);
void ListPermutations2(char *str);

int main(int argc, char *argv[])
{
	char str[] = "AABC";
	ListPermutations(str);
	printf("-------------------------------\n");
	ListPermutations2(str);
	return 0;
}

static void ExchangeChar(char *str, int p1, int p2)
{
	char temp;

	temp = str[p1];
	str[p1] = str[p2];
	str[p2] = temp;
}

static void RecursivePermute(char *str, int k)
{
	int i;

	if (strlen(str) == k) {
		printf("%s\n", str);
	} else {
		for (i = k; i < strlen(str);i++) {
			ExchangeChar(str, k, i);
			RecursivePermute(str, k+1);
			ExchangeChar(str, k, i);
		}
	}
}

void ListPermutations(char *str)
{
	RecursivePermute(str,0);
}


static char *setstr(char *str)
{
	char buf[10];int i;int flag;
	char *p = NULL;
	p = buf;
	memset(buf,0,10);
	flag = 0;
	for (i = 0; i < strlen(str);i++) {
		int j;
		for (j = 0; j < strlen(buf); j++) {
			if (buf[j] == str[i]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			flag = 0;
			continue;
		}
		*p++ = str[i];
	}
	return strdup(buf);
}

static void delchar(char *str, char c)
{
	int i;char *p;
	p = str;
	for (i = 0; i < strlen(str); i++) {
		if (p[i] == c) {
			p = p+i;
			for (p;*p!=0;p++) {
				*p=*(p+1);
			}
			*p = 0;
			break;
		}
	}
}


static void RecursivePermute3(char *prefix, char*substr)
{
	char *set = setstr(substr);
	int i;
	if (strlen(set) == 1) {
		char rbuf[10];
		memset(rbuf,0,10);
		strcat(rbuf,prefix);
		strcat(rbuf,substr);
		printf("%s\n", rbuf);
	} else {
		for (i = 0; i < strlen(set); i++) {
			char buf[2]; char *tmp = NULL;
			int j;
			buf[0] = set[i];
			buf[1] = 0;
			strcat(prefix,buf);
			tmp = strdup(substr);	
 			delchar(tmp, set[i]);
			RecursivePermute3(prefix, tmp);
			prefix[strlen(prefix)-1] = 0;
			free(tmp);
		}
	}
	free(set);
}


void ListPermutations2(char *str)
{
	char *p;int i;char *tmp;
	char *buf = (char *)malloc(strlen(str)+1);
	memset(buf,0,strlen(str)+1);

 	RecursivePermute3(buf,str);
 
	free(buf);
}
