#include<stdio.h>
int main(void)
{
    int len;
    char str1[500] ="Hello" ;
    char str2[500] = "World";
    char str3[500];
    mstrcpy(str3,str1);
    printf("%s\n",str3);
    mstrcat(str2,str1);
    printf("%s\n",str1);
    len = mstrlen(str3);
    printf("%d",len);
    return 0;
}
int mstrlen(char str1[500])
{
    int x,sum=0;
    for(x=0; str1[x]!='\0'; x++)
    {
        sum++;
    }
    return sum;
}

void mstrcpy(char str2[],char str1[])
{
    int i;
    for(i=0; str1[i]!='\0'; i++)
    {
        str2[i]=str1[i];
    }
    str2[i]=str1[i];
}

void mstrcat(char str2[],char str1[])
{
    int i;
            for(i=0;str1[i]!='\0';i++){
                str1[i+mstrlen(str2)] = str2[i];
            }
           str1[i+mstrlen(str2)] = str2[i];
 }
