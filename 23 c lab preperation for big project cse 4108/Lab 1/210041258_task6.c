#include<stdio.h>
int main()
{
	/*
        area of triangle = 0.5 * b * h
	*/
	float base,height,area;
	printf("ENTER THE BASE OF TRIANGLE AND THE HEIGHT :\n");
	scanf("%f %f",&base,&height);
    area = base*height* 0.5 ;
	printf("THE AREA OF TRIANGLE = %.3f", area);

    return 0 ;
}
