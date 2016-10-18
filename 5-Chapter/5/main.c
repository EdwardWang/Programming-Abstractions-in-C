#include <stdio.h>
#include <string.h>

static char *dstr[] = {"0",
					 "",
					 "ABC",
					 "DEF",
					 "GHI",
					 "JKL",
					 "MNO",
					 "PRS",
					 "TUV",
					 "WXY",
					 ""
};

void ListMnemonics(char *str);

int main(int argc, char *argv[])
{
	ListMnemonics("7233");
}

static void sub_mnemonics(char *prefix, char *substr)
{
	if (*substr == 0) {
		printf("%s\n", prefix);
	} else {
		int i;
		char *ds = strdup(dstr[substr[0]-'0']);
		for(i = 0; i < strlen(ds);i++) {
			char buf[10];
			memset(buf,0,10);
			strcat(buf,prefix);
			buf[strlen(buf)] = ds[i];
			buf[strlen(buf)] = 0;
			sub_mnemonics(buf, substr+1);
		}
		free(ds);
	}
}

void ListMnemonics(char *str)
{
	char buf[10];
	memset(buf,0,10);
	sub_mnemonics(buf, str);
}
