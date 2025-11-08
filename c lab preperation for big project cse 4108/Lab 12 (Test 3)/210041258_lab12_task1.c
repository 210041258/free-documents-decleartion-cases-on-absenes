#include<stdio.h>
#include<math.h>
int chocolateFeast(int n,int c, int m);
int main()
{
    int n,c,m,z[100],t;
    scanf("%d",&t);
    int d;
    for(d=0; d<t; d++)
    {
        scanf("%d %d %d",&n,&c,&m);
        if((1<=t)&&(t<=1000))
        {
            if((2<=n)&&(n<=pow(10,5)))
            {
                if((1<=c)&&(c<=n))
                {
                    if((2<=m)&&(m<=n))
                    {
                        z[d] = chocolateFeast(n,c,m);
                    }
                }
            }
        }
    }
for(d=0; d<t; d++){
        printf("%d\n",z[d]);
    }

    return 0;
}
int chocolateFeast(int n, int c, int m )
{
    int total_bars;
    int x,y;
    x = n / c;
    if(x>=m){
        y = m/x;
        x =x+y;
    }
    total_bars = x;
    return total_bars;
}
