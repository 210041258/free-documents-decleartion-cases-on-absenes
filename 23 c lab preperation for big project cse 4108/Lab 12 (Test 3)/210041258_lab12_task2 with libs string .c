#include<stdio.h>
#include<string.h>

int superDigit(char *num);
int dividing(int number,int len);

int main()
{
    char num[500];
    int x;
    gets(num);
    x = superDigit(num);
    printf("%d",x);
    return 0;
}

int superDigit(char *num)
{
    int x,main_number,z,o,len,superDigit;
    len =(strlen(num));
    main_number = atoi(num);
    z =dividing(main_number,len);
    while(z>10)
    {
        main_number=z;
        z =dividing(main_number,len);
    }
    return z;
}


int dividing(int number,int len)
{
    int x,array1[500],sum=0;
    for(x=0; x<len; x++)
    {
        array1[x]=(number%10);
        number = number/10;
    }
    for(x=0; x<len; x++)
    {
        sum+=array1[x];
    }

    return sum;
}
