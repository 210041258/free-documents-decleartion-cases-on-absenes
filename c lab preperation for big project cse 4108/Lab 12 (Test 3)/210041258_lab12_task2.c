#include<stdio.h>
#include <stdlib.h>

int superdigit(char* num);
int dividing(int result);

int main()
{
    int dig=1,i=0,sum=0,s;
    int x1[500];
    while(x1[i]!=0&&dig<=500)
    {
        scanf("%d",&x1[i]);
        ++dig;
        ++i;
    }
    char nums[500];
    for(s=0;s<i;s++){
        nums[s]=x1[i];
    }nums[s]='\0';
    int as = superdigit(nums);
    printf("%d",as);
    return 0;
}

int superdigit(char* num)
{
    int soo,u,s,sum=0,i,b[500],a[500],e;
    for(e=0;*(num+e)<1000;e++){
        b[e]=*(num+e);
    }
    for(i=0; b[i]>0; i++)
    {
        sum+=b[i];
    }
    for(s = 0 ; u > 10 ; s++)
    {
         u = dividing(sum);
    }
    return u;
}

int dividing(int result)
{
    int t,i;
        for(i=0; result>0;i++)
        {
            result = (result/10);
             t = (result%10);
        }
    return result;
}
