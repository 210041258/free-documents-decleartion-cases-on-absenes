#include <stdio.h>

int main(void){
	int number,i,remainder=0,sum=0,greatest=0;
	scanf("%d",&number);
	while(number!=0){
    while(number!=0){
        sum += number % 10;
        number = number / 10;
    }
		if(greatest<sum){greatest=sum;}
		scanf("%d",&number);
		}
	printf("%d",greatest);
	return 0;
}