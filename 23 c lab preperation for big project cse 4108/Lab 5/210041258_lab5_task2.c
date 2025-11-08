


#include<stdio.h>
#include <stdlib.h>


int main()
{
    int c,i,n;
    int user_role,exit,total_attep = 1,total_playing =0,guss_role,  access_score = 0 ;
;
    printf("Welcome to Guessing Game \n");
    printf("Rule Of The Game \n The Computer Will Take The Number \n You must guess which number is it  ");
    printf("\n \n Note If You Went To Go Out Of Game You Can Submit 0 \n ");
    printf("\n Let's Start ... \n");
    printf("\n Computer Take Number \n");
    printf("\n Your role \n");
    scanf("%d",&user_role);

    while(user_role != 0){

        total_playing++;

//the start of guessing area for computer

        for( i = 1 ; i <= 1024 ; i++ )
        {
            guss_role = rand() % 1024 + 1 ;
            break;
        }

//the end of guessing area for computer


        while(user_role != guss_role)
        {
            printf("\n game Over !! ");
            printf("\n Try Again ");
            total_attep = 1 + total_attep;
            printf("\n Your new Role \n");
            scanf("%d",&user_role);
            break;
        }


     while(user_role == guss_role)
        {
            printf("\n Good Job \n");
            access_score = 1 ;
            printf("\n Your Score is : %d",total_attep);
            printf("\n Let's Start Again  ");
            printf("\n Computer Take Number");
            printf("\n Your New Role \n");
            scanf("%d",&user_role);
            break;
        }
    }


    while (user_role == 0)
        {

        if(total_playing){
            if (access_score){
            printf("\n Good Bye ,  See you Later  \n");
            printf("\n  Your Last Score is : %d \n",total_attep);
            }
        }
        if(total_playing == 0 || access_score == 0 ){
            printf("\n Good Bye ,  See you Later  \n");\
        }

        break;
    }
    return 0 ;
}
