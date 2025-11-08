#include<stdio.h>
int main()
{
     // making a variable and get some input to complete program

    int averagemarks,wrong_answers,total_answers,total_lost_marks,lost_questions,lost_marks;
    printf(" Enter your total of your answered questions : \n");
    scanf("%d", &total_answers);
    printf(" Enter your total of your Wrongs questions : \n");
    scanf("%d", &wrong_answers);

    // function for check user values

    if(wrong_answers >= total_answers){
            printf(" you must enter your correct value for your wrong questions thats can't be more than total answered \n");
            printf(" Enter your total of your Wrongs questions : \n");
            scanf("%d", &wrong_answers);

    //  function to check the result

            lost_questions = 100 - total_answers;
            total_lost_marks = wrong_answers *0.25;
            lost_marks = total_lost_marks + lost_questions;
            averagemarks = 100 - lost_marks;

            if(averagemarks <= 70 && averagemarks >= 40){
                printf("you have the a self finacnced admtisstion offer");
            }
                else if(averagemarks >=70 && averagemarks <= 95){
                    printf("you have the a partial finacnced admtisstion offer");
                }
                    else if(averagemarks >= 95){
                        printf("you have the a full finacnced admtisstion offer");
                    }
                       else{
                            printf(" you can't a get your admtisstion in our unviersaty");
                        }

            printf("\n your average is : %d",averagemarks );

    }
    else{


        //averagemarks = ( total_answers - wrong_answers ) - (wrong_answers * 0.25);

         lost_questions = 100 - total_answers;
         total_lost_marks = wrong_answers *0.25;
         lost_marks = total_lost_marks + lost_questions;
         averagemarks = 100 - lost_marks;

            // the same function to check the result

        if(averagemarks <= 70 && averagemarks >= 40){
            printf("you have the a self finacnced admtisstion offer");
        }
            else if(averagemarks >=70 && averagemarks <= 95){
                printf("you have the a partial finacnced admtisstion offer");
            }
                else if(averagemarks >= 95){
                    printf("you have the a full finacnced admtisstion offer");
                }
                   else{
                        printf(" you can't a get your admtisstion in our unviersaty");
                    }


        printf("\n your average is : %d",averagemarks );
    }
            return 0 ;

}
