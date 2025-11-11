#include <stdio.h>

int main(void) {
  int n,m;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
       if(i==j || j==(n-i+1))
       {
         printf("*");
       }
       else
       {
         printf(" ");
       }
    }
    printf("\n");
  }
  return 0;
}
