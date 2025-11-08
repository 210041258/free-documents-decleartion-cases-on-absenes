#include<stdio.h>
int main()
{
    int n,x,i,j,final_res=0,final_res_1=0;
    scanf("%d",&n);
    int z=0,m[n],b[n];
    if((1<=n)&&(n<=1000))
    {
        for(x=0; x<n; x++)
        {
            scanf("%d",&m[x]);
        }

        for(x=0; x<n; x++)
        {
            scanf("%d",&b[x]);
        }

            if((1<=b[x])&&(b[x]<=(10*10*10*10*10*10*10*10*10*10)))
            {
                if((1<=m[x])&&(m[x]<=(10*10*10*10*10*10*10*10*10*10)))
                {
                    if((m[x]!=(m[x+1]))||(b[x]!=(b[x+1])))
                    {
                for(i=0; i<n; i++)
                {
                    if(m[i]==b[i])
                    {
                        final_res++;//same postion and same value
                    }
                }

                for(i=0; i<n; i++)
                {
                    for(j=0; j<n; j++)
                    {
                        if((b[i]==m[j])&&(b[j]!=m[j]))
                        {
                            final_res_1++;//different postion and same value
                        }
                    }

                }
            }
        }
            }

    }
    printf("%d \n%d",final_res,final_res_1);
        return 0;
}
