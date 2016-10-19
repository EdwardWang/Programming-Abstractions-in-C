#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *Reverse(char *str);

int main(int argc, char *argv[])
{
    char *str;
    str = Reverse("program");
    printf("%s %s\n", "program", str);
    free(str);
    return 0;
}

char *Reverse(char *str)
{
    if (strlen(str) == 1) {
        return strdup(str);
    } else {
        char buf[20];char *rstr;
        memset(buf, 0,20);
        rstr = Reverse(str+1);
        strcpy(buf,rstr);
        buf[strlen(buf)] = *str;
        buf[strlen(buf)] = 0;
        free(rstr);
        return strdup(buf);
    }
}
