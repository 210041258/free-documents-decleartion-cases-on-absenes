#include<stdio.h>

int main()
{
    int x,f=0,n,k,z[2000],z1[2000];
    scanf("%d %d",&n,&k);
    if(((1<=n)&&(n<=2000))&&((1<=k)&&(k<=5)))
    {
        for(x=0; x<n; x++)
        {
            scanf("%d",&z[x]);

        if((z[x]+k)<=5)
        {
            ++f;
        } }
    }
        printf("%d",f/3);
        return 0;
    }
