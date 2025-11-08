#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* mstrstr(char* str1,char* str2)
{
    char* s = NULL;
    int x,y,able=0,t=-1;
    int len1 = ((strlen(str1))-1),len2 = ((strlen(str2))-1);
    if(!(strcmp(" ",str2)))
    {
        s = &str1;
        return s;
    }
    for(x=0,y=0; x<=len1; x++)
    {
        if(str1[x]==str2[y])
        {
            ++y;
            ++t;
            able =1;
        }
        if((t == len2) && (able))
        {
            s = &str2;
            return s;
        }
    }

// this line for checking which value will return
    if(s != NULL)
    {
        return s;
    }
    else
    {
        return NULL;
    }
}


int main(void)
{
    char str1[100],str2[100];
    char* st;
    gets(str1);
    gets(str2);
    st = mstrstr(str1,str2);
    printf("%p",st);
    return 0;
}
