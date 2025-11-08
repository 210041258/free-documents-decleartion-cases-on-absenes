#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* mstrrchar(char* str,char c){
    char* g;
    int x;
    int len =(strlen(str)-1);
    for(x=len;x>=0;x--){if(str[x]==c){g =&str[x];return g;}}
return NULL;
}
int main(){
    char* a;
    char str1[100];
    char b;
    gets(str1);
    scanf("%c",&b);
    a = mstrrchar(str1,b);
    printf("%p",a);
    return 0;
}
