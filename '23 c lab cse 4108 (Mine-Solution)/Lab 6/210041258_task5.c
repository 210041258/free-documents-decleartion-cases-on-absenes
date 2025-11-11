#include<stdio.h>
int main(){
    int z,gcd,numerator,denominator,numerator_2,denominator_2;
    scanf("%d  %d", &numerator, &denominator);
    for(z = 1 ; z <= numerator && z <=denominator ; ++z){
        if (numerator%z==0 && denominator%z==0){
            gcd = z;
            }
    }
    // here we are savinf 0.7s of our cpu time of ext.
    denominator_2=  denominator/ gcd ;
    numerator_2 =  numerator/ gcd ;
    printf("%d / %d ",numerator_2,denominator_2);

    return 0;
}
