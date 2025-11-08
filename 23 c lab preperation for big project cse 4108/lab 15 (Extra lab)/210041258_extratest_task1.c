#include<stdio.h>

int main(){
    int i,i1,i3;
    int x,op,y,n,sum=0;
    int final;
    scanf("%d %d %d",&x,&y,&n);
    if((1<=x)&&(x<=100)){
    if((x<=y)&&(y<=100)){
    if(((1<=n)&&(n<=100))){
        while ((n/3) >=0)){
            sum+=y;
            if(n==0){
                break;
            }
        }
        while (((n/3) >=0))&&(n!=0)){
            sum+=x;
           if(n==0){
                break;
            }
        }

        printf("%d",sum);
    }}}
    return 0;
}
