#include<stdio.h>
int main(){
    printf(" Enter 3 Number Please (for example (1 2 3)) \n ");
    int a,b,c ;
    scanf("%d %d %d",&a,&b,&c);

    if (a > b  && a > c){
            printf("the %d is greater one",a);
    }
    else if(b>a  && b>c){

            printf("the %d is greater one",b);

    }
    else if(c>a  && c>b){
            printf("the %d is greater one",c);
    }
    else printf("the numbers are equal");

    return 0 ;

}

