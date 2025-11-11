#include<stdio.h>
#include<string.h>
char super_digit(char *str, int x);
int main()
{
    char a[100005],b[100005];
    long long n,i,k,count=0,j;
    scanf("%lld",&n);
    scanf("%lld",&k);
    j=n;
    while(j!=0)
    {
        if(j%10!=0)
            count++;
        j=j/10;
    }
    j=n;

    for(i=count-1;i>=0;i--)
    {
        a[i]=(j%10)+48;
        j=j/10;
    }


    int x=strlen(a);
    for(i=0;i<x;i++)
    {
        b[i]=a[i];
    }
    for(i=0;i<k-1;i++)
    {
        strcat(a,b);
    }
    int y=strlen(a);


    printf("%c",(super_digit(a,y)));
    return 0;

}
char super_digit(char *str, int x)
{
    int sum=0,i,sum2=0;
    for(i=0;i<x;i++)
    {
        sum+=str[i]-48;
    }
    if (sum<10)
        return sum+48;
    else
    {
        while(1)
        {
          sum2=sum;
          sum=0;
          while(sum2!=0)
          {
              sum+=sum2%10;
              sum2=sum2/10;
          }
          if(sum<10)
          {

              return sum+48;
          }
        }

    }
}

