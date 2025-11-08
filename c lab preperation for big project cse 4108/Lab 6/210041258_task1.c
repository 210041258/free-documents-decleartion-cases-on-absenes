#include<stdio.h>
int main(){
    int rows ,y,x;
    scanf("%d",&rows);
    if (1<=rows && rows<=100){
        for(y = 1 ;y<=rows;y++){
                for(x =1 ; x <= y; x++){
                    printf("*");

                }        printf("\n");

        }
    }
    return 0;
}
