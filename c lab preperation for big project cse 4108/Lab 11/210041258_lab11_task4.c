#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* mstrlwr(char* str)
{
    int u=0;
    int x;
    int len =(strlen(str)-1);
    char* s =NULL;
    for(x=0; x<=len; x++)
    {
        if((str[x]>='A')&&(str[x]<'a'))
        {
            str[x]+=('a'-'A');
            if(u == 0){
            u=1;
            s=&str[x];
            }
        }
    }
    if(s != NULL){ return s;}
    else{return NULL;}
}

int main(void)
{
    char* s;
    char str[100];
    gets(str);
    s = mstrlwr(str);
    printf("%s \n",str);
    printf("%p",s);
    return 0;
}
