#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* mstrupr(char *str)
{
    int x ;
    char* s =NULL;
    int u=1;
    int len = (strlen(str)-1);
    for(x=0; x<=len; x++)
    {
        if((str[x]>='a')&&(str[x]<='z'))
        {
            str[x]-=('a'-'A');
            if(u==1)
            {
                s = &str[x];
                u=0;
            }
        }
    }
    if(s != NULL){return s;}
    else return NULL;
}
int main (void)
{
    char* r;
    char str[100];
    gets(str);
    r = mstrupr(str);
    printf("%s \n",str);
    printf("%p",r);
    return 0;
}
