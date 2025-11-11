#include<stdio.h>
int main(){
    int x ,y,z,a,b,c;
    scanf("%d",&y);
    for (x =1 ; x<=y;x++){
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        if((a+b >= c )  &  (a+c  >= b)  & ( b+c  >= a )){
                if ((a == b)&(b == c)){
                    printf("case %d : Equilateral \n",x);
                }
                else if((a == b)||(b == a)||(a==c)){
                    printf("case %d : Isosceles \n",x);
                }
                else if ((a != c)&(a !=b)){
                    printf("case %d : Scalene \n",x);
                }
        }
        else {
                printf("case %d : invaild input \n",x );
        }
    }
    return 0;
}
