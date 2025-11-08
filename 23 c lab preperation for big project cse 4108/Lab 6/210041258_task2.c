#include<stdio.h>
int main()
{
    int x,y,z,h,c,rows;
    scanf("%d",&rows);
    for(x =1 ; x<=rows; x++)
    {
        for(z =1; z<=(rows-x); z++)
        {
            printf(" ");
        }
        for(y =1 ; y<x; y++)
        {
            printf("*");
        }
        for(h =1 ; h <=(x-rows); h++)
        {
            printf(" ");
        }
        for(c = 1; c <=(x); c++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0 ;
}
