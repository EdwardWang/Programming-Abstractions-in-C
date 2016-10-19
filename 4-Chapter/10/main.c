#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *IntegerToString(int n);

int main(int argc, char *argv[])
{
    char *str = IntegerToString(1860);
    printf("%s\n", str);
    free(str);
    return 0;
}

char *IntegerToString(int n)
{
    if(n/10 == 0) {
        char buf[2];
        buf[0] = n+'0';
        buf[1] = 0;
        return strdup(buf);
    } else {
        char buf[20];char *prestr;
        memset(buf,0,20);
        prestr = IntegerToString(n/10);
        strcpy(buf, prestr);
        free(prestr);
        buf[strlen(buf)] = ((n%10)+'0');
        buf[strlen(buf)] = 0;
        return strdup(buf);
    }
}
