#include<stdio.h>
int main(){
    int x , n ,o,op=0;
    scanf("%d",&n);
    if((1<=n)&&(n<=100)){

        for(x =1;x<=n;x++){
            scanf("%d",&o);
            op += o;

        }


                if(op >= 1 ){
                    printf("HARD");
            }
            else{
                printf("EASY");
            }


             }
            else{
        printf(" invaild input ");
            }
    return 0;
}
