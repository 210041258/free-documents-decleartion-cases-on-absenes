#include<stdio.h>

int main()
{
    int n,x,i,j;
    scanf("%d",&n);
    int z[n],z1[n],p[n];
    if((1<=n)&&(n<=106))
    {
        for(x=0; x<n; x++)
        {
            scanf("%d",&z[x]);
            if(!((0<=z[x])&&(z[x]<=106)))
            {
                exit(0);
            }
            z1[x]=z[x];
        }
        for(i=0; i<n-1; i++)
        {
            int swapped =0;
            for(j=0; j<n-1-i; j++)
            {
                if((z[j])>(z[j+1]))
                {
                    int yy = z[j];
                    z[j] = z[j+1];
                    z[j+1] = yy;
                    swapped =1;
                }
            }
            if(!(swapped))
            {
                break;
            }
        }
      for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(z[i]==z1[j]){
                    p[i]=j;
                }
            }
      }
    }


    for(x=0; x<n; x++)
    {
        printf("%d ",p[x]);
    }
    return 0;
}
