#include<stdio.h>
#include<string.h>
int mystrcmp(char* str2,char* str1)
{
    int x,len1=(strlen(str1)-1),sum = -1;
    for(x=0; x<=len1; x++)
    {
        if(str2[x]==str1[x])
        {
            sum++;
        }
        else if(str2[x]>str1[x])
        {
            return 1;
        }
        else if(str2[x]<str1[x])
        {
            return -1;
        }
    }

    if(sum == len1)
    {
        return 0 ;
    }
}
int main(void)
{
    int x ;
    char str2[500], str1[500];
    gets(str2);
    gets(str1);
    x = mystrcmp(str2,str1);
    printf("%d",x);
}
