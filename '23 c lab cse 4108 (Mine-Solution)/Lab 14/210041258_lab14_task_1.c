#include<stdio.h>
#include<stdlib.h>
int main(int r,char* arr[])
{
    int x=atoi(arr[1]),y=atoi(arr[2]);
    int i,d=0,times=0;
    printf("%d prime numbers is starting from %d is listed below : \n",x,y);
    for(i=0; times<x; y++)
    {
        d = prime(y);
        if(d){printf("%d\t",y);++times;}
    }
    return 0;
}

int prime(int number, int d)
{
    int loop = 2;
    int for_var;
    int prime =1;
    for(for_var = 0; loop < number ; ++loop)
    {
        if((number%loop)==0)
        {
            prime =0;
        }
    }
    if(prime ==1)
    {
        return 1;
    }
    return 0;
}
