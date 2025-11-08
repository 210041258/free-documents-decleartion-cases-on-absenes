#include<stdio.h>
int main(){
    int x,y,z,gcd;
    scanf("%d %d",&x,&y);
    for(z = 1 ; z <= x && z <=y ; ++z){
        if (x%z==0 && y%z==0){
            gcd = z;
            }
    }
    printf("GCD of %d and %d is: %d\n",x,y,gcd);

    return 0;
}
