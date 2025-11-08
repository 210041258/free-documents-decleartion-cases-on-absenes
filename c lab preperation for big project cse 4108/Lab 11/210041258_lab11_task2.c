#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* mstrchar(char* str,char c)
{
    int x;
    char* v;
    int len = (strlen(str)-1);
    for(x=0; x<=len; x++)
    {
        if(c==str[x])
        {
            v=&str[x];
            return v;
        }
    }
    return NULL;
}

int main(void)
{
    char* x;
    char z,str[100];
    gets(str);
    scanf("%c",&z);
    x = mstrchar(str,z);
    printf("%p",x);
    return 0;
}
