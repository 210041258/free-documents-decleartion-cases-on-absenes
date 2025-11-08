#include<stdio.h>
int main(){
    int fisrtnum, secondnum ;
    printf("Enter your first number: ");
    scanf("%d", &fisrtnum);
    printf("Enter your second number: ");
    scanf("%d", &secondnum);
    //printf("%d %d", fisrtnum, secondnum);
    if (fisrtnum == secondnum){
        printf(" The Two Values is equeled ");
}
    else if(fisrtnum > secondnum){
        printf("the First number %d is Greater Than %d the second number",fisrtnum,secondnum);
    }
    else if(fisrtnum < secondnum){
        printf("the second number %d is Greater Than %d the first number",secondnum,fisrtnum);
    }

    return 0 ;
}

