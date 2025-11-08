#include <stdio.h>
#include <string.h>
void xorCrypt(char *str, char key)
{
    int x,len=strlen(str-1);
    for(x=0;x<=len; x++)
    {
        str[x]^=(key);
    }
}

int main()
{
    char x;
    char word[100];
    gets(word);
    char word1[100];
    strcpy(word1,word);
    scanf("%c",&x);
    xorCrypt(word,x);
    printf("Decrypted: ");
    puts(word);
    printf("\n");
    printf("Eecrypted: ");
    puts(word1);
    printf("\n");
    return 0;
}
