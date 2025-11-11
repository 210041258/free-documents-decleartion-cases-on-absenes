/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int x , y  ;
    float z , e ;
    scanf("%d %d",&x,&y);
    scanf("%f %f",&z,&e);
    if (((1 <= x)&&( x <= 10^4))&&(((1 <= y)&&( y <= 10^4)))){
        printf("%d %d  \n",(x + y ), (x-y));
    }
    if (((1 <= z)&&( z <= 10^4))&&(((1 <= e)&&( e <= 10^4)))){
        printf("%.1f %.1f ",(z + e ), (z-e));

    }
    return 0;
}
