#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int x;
    float z[n];
    for(x=0;x<n;x++){
        scanf("%g",&z[x]);
    }
    float sum =0;
    float highest = z[0];
    float lowest = z[0];
    for(x=0;x<n;x++){
            sum += z[x];

        if(highest<z[x]){
            highest = z[x];
        }
        if(lowest>z[x]){
            lowest = z[x];
        }
    }
    int i ,j;
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
    float median ;
    if(n%2==0){
        median = ((z[n/2] + z[(n/2)-1])/2.0);
    }
    else{
        median = z[(n/2)+1];
    }
    printf("Min: %g\n",lowest);
    printf("Max: %g\n",highest);
    printf("Mean: %g\n",((sum)/(n)));
    printf("Median: %g\n",median);
    return 0;
}
