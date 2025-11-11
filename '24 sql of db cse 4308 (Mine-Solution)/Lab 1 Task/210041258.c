#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *grades_file,*std_info_file;

typedef struct std_grades_
{
    unsigned long int std_id ;
    float gpa ;
    unsigned int semster ;
} std_grades_format;

typedef struct std_info_
{
    unsigned long int std_id ;
    char name[11];
    unsigned long int age ;
    char blood_group[11];
    char department[11];
} std_info_format;

typedef struct std
{
    unsigned long int std_id ;
    float cgpa ;
    char name[11] ;
} std_info_output;

// functions that must be inside the program
void first_function();
void second_function();
void third_function();


int check_id(unsigned long int std_id);


int main()
{
    int no_function=0;
    printf("\n\t 1- First Function AS "" Show who has Highest GPA inside the list ""\n");
    printf("\t 2- Second Function AS "" Enter the new student to the list ""\n");
    printf("\t 3- Third Function AS "" Searching for Spacific Student Info By Student ID ""\n");
    printf("\t Enter The Number of the Function : ");
    scanf("%d",&no_function);
    if(no_function==1)
    {
        system("cls()");
        first_function();
    }
    else if (no_function==2)
    {
        system("cls()");
        second_function();
    }
    else if (no_function==3)
    {
        system("cls()");
        third_function();
    }
    return 0;
}

void first_function()
{
    char buffer[1024];
    std_grades_format std_tmp_info,std_highest_info= {111111,2.5,1};
    grades_file = fopen("grades.txt","r+");
    while(fgets(buffer,1024,grades_file)!=NULL)
    {
        sscanf(buffer,"%ld;%f;%u\n",&std_tmp_info.std_id,&std_tmp_info.gpa,&std_tmp_info.semster);
        if(std_tmp_info.gpa >  std_highest_info.gpa)
        {
            std_highest_info.std_id = std_tmp_info.std_id;
            std_highest_info.gpa = std_tmp_info.gpa;
            std_highest_info.semster = std_tmp_info.semster;
        }
    }
    fclose(grades_file);
    printf(" The highest student gpa id number : ");
    printf("%lu, the gpa is :%.2f",std_highest_info.std_id,std_highest_info.gpa);
    printf("\n");
    sleep(3);
    if(putchar("\n"))
    {
        system("cls");
        main();
    }

}

void second_function()
{
    char buffer[1024];
    std_grades_format new_std;
    std_info_file = fopen("grades.txt","a");
    printf(" Enter the Student ID : ");
    scanf("%ld",&new_std.std_id);
    if(!check_id(new_std.std_id))
    {
        printf("\n Enter the GPA : ");
        scanf("%f",&new_std.gpa);
        if((2.5<= new_std.gpa )&&(new_std.gpa<=4)){
        printf("\n Enter the Your Semster  : ");
        scanf("%u",&new_std.semster);
        if(1<=new_std.semster&&new_std.semster<=8){
        sprintf(buffer,"%ld;%.2f;%u\n",new_std.std_id,new_std.gpa,new_std.semster);
        fputs(buffer,std_info_file);
        printf("done ! ");
            sleep(3);
        if(putchar("\n"))
        {
        system("cls");
        main();
        }

    }}}

    else{
        printf("Check your information");
            sleep(3);
        system("cls");
        second_function();

}}
int check_id(unsigned long int std_id)
{
    grades_file = fopen("grades.txt","r+");
    std_grades_format tmp_std_;
    char buffer4[1024];
    while(fgets(buffer4,1024,grades_file)!=NULL)
    {
        sscanf(buffer4,"%ld;%f;%u\n",&tmp_std_.std_id,&tmp_std_.gpa,&tmp_std_.semster);
        if(std_id==tmp_std_.std_id)
        {
            return 1;
        }
    }
    return 0;
}

void third_function()
{
    char buffer[1024];
    std_info_output shown_std_info;
    std_grades_format std_grades ;
    std_info_format std_info;
    int max_semster=0;
    float sum_gpa=0;
    scanf("%ld",&shown_std_info.std_id);
    grades_file = fopen("grades.txt","r+");
    while(fgets(buffer,1024,grades_file)!=NULL)
    {
        sscanf(buffer,"%ld;%f;%u\n",&std_grades.std_id,&std_grades.gpa,&std_grades.semster);
        if(shown_std_info.std_id==std_grades.std_id)
        {
            sum_gpa=+std_grades.gpa;
            if(max_semster<std_grades.semster)
            {
                max_semster = std_grades.semster;
            }
        }

    }
    fclose(grades_file);
    char buffer3[1024],buffer2[1024];
    shown_std_info.cgpa = sum_gpa/max_semster;
    std_info_file = fopen("studentInfo.txt","r");
    while(fgets(buffer2,1024,std_info_file)!=NULL)
    {
        sscanf(buffer2,"%ld;%s;%ld;%s;%s\n",&std_info.std_id,std_info.name,&std_info.age,std_info.blood_group,std_info.department);
        if(shown_std_info.std_id==std_info.std_id)
        {
            strcpy(shown_std_info.name,std_info.name);
        }
    }
    fclose(std_info_file);
    if(max_semster==0)
    {
        printf(" the Student ID does not exist in your database \n");
    }
    else
    {
        printf("\t NAME : %s \n \t CGPA : %.3f \n ",shown_std_info.name,shown_std_info.cgpa);
    }
    sleep(3);
    if(putchar("\n"))
    {
        system("cls");
        main();
    }
}

