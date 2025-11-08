#include <stdio.h>

int main(void)
{
    int x,y,m,z,num,a,apo[10000],bpo[10000];
    apo[0] =0;
    bpo[0]=0;
    scanf("%d %d", &x,&y);
    for(z=1; z<=2; z++)
    {
        scanf("%d", &apo[z]);
    }
    for(z=1; z<=2; z++)
    {
        scanf("%d", &bpo[z]);
    }

    for(m=1; m<=y; m++)
    {
        for(z=1; z<=x; z++)
        {
            if(apo[1]==z && apo[2]==m)
            {
                printf("A");
            }
            else if(bpo[1]==z && bpo[2]==m)
            {
                printf("B");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}
