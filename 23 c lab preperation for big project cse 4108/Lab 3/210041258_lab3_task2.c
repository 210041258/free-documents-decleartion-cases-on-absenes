#include <stdio.h>
#include <math.h>
int main(void){
	int a , b , _10power6 , number , remain_of_number ;
	scanf("%d",&a);
	scanf("%d",&b);
	_10power6 = pow(10,6);
    if ((1 <= a) && (a <= _10power6 ))
    {
        if ((1 <= b) && (b <= _10power6 ))
            {
             // the code will start from here


              for( number = a ; number <= b ; number++)
                {

                    if ( 1 <= number && number <= 9){
                        if (number == 1){
                            printf("one\n");
                    }
                        if (number == 2){
                            printf("two\n");
                    }
                        if (number == 3){
                            printf("three\n");

                    }
                        if (number == 4){
                            printf("four\n");
                    }
                        if (number == 5){
                            printf("five\n");
                    }
                        if (number == 6){
                            printf("six\n");
                    }
                        if (number == 7){
                            printf("seven\n");
                    }
                        if (number == 8){
                            printf("eight\n");
                    }
                        if (number == 9){
                            printf("nine\n");
                    }
                }

                    if (number > 9){
                        remain_of_number = number % 2 ;

                        if (remain_of_number == 0 ){
                            printf("even\n");
                    }

                        if(remain_of_number != 0){
                            printf("odd\n");
                    }
                    }
             }
        }
    }
	return 0;
}
