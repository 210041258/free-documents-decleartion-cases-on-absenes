#include<stdio.h>
int main(){
    int n,i,sum=0,num;
    scanf("%d",&n);
    if((10000<=n)&&(n<=99999)){
        for(i=0;i<5;i++){
        num=n%10;
        n/=10;
        sum+=num;
        }
    printf("%d",sum);
    }

    return 0;
}

