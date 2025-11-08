#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int z[n];
    int x;
    for(x=0; x<n; x++)
    {
        scanf("%d",&z[x]);
    }
    int z1[n];
    int i, j;
    for(i=0; i<n-1; i++)
    {
        int swapped =0;
        for(j=0; j<n-1-i; j++)
        {
            if((z[j])>(z[j+1])){
                int yy = z[j];
                z[j] = z[j+1];
                z[j+1] = yy;
                swapped =1;
            }
        }
        if(!(swapped)&&(i==0))
        {
            printf("Yes");
            break;
        }
        if(!(swapped))
        {
            printf("No\n");
            for(x=0; x<n; x++)
            {
                printf("%d ",z[x]);
            }
            break;
        }
    }
    return 0;
}
