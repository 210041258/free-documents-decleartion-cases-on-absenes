#include<stdio.h>
#include<string.h>




struct address
{
    int Road_number;
    int House_number;
    char City[50];
    int Zip_code;
};
struct student
{
    char Name[50];
    float CGPA ;
    int Merit_Position;
    struct address ad;
};


int main()
{
    float  a;
    int i,j;
    struct student student_1,student_2,student_3,student_4,student_5;
    //1
    strcpy(student_1.Name,"Ahmed");
    student_1.CGPA =3.00;
    student_1.Merit_Position = 1 ;
    student_1.ad.Road_number =1;
    student_1.ad.House_number =1;
    student_1.ad.Zip_code =12345;
    strcpy(student_1.ad.City,"Gaza");
    //2
    strcpy(student_2.Name,"mohmed");
    student_2.CGPA =2.10;
    student_2.Merit_Position = 12 ;
    student_2.ad.Road_number =13;
    student_2.ad.House_number =51;
    student_2.ad.Zip_code =18915;
    strcpy(student_2.ad.City,"ramallah");
    //3
    strcpy(student_3.Name,"jamin");
    student_3.CGPA =2.80;
    student_3.Merit_Position = 3 ;
    student_3.ad.Road_number =2;
    student_3.ad.House_number =15;
    student_3.ad.Zip_code =14355;
    strcpy(student_3.ad.City,"alnasira");
    //4
    strcpy(student_4.Name,"lkman");
    student_4.CGPA =3.50;
    student_4.Merit_Position = 5 ;
    student_4.ad.Road_number =56;
    student_4.ad.House_number =2;
    student_4.ad.Zip_code =98758;
    strcpy(student_4.ad.City,"kanyouns");
    //5
    strcpy(student_5.Name,"ramo");
    student_5.CGPA =2.00;
    student_5.Merit_Position = 3 ;
    student_5.ad.Road_number =4;
    student_5.ad.House_number =5;
    student_5.ad.Zip_code =21365;
    strcpy(student_5.ad.City,"juresulm");

    float num[5]= {student_1.CGPA,student_2.CGPA,student_3.CGPA,student_4.CGPA,student_5.CGPA};
    sort_floats_comare_it_printf_all_strcuture(num,student_1,student_2,student_3,student_4,student_5);

    return 0;
}

void print_of_struct(struct student sd)
{
    printf("\n \n Student Name  : %s \n",sd.Name);
    printf("the Cgpa is : %.2f \n",sd.CGPA);
    printf("the merit postion : %d \n",sd.Merit_Position);
    printf("the address of student \n the road number : %d \n the house number : %d \n the zip code : %d \n the city : %s \n",sd.ad.Road_number,sd.ad.House_number,sd.ad.Zip_code,sd.ad.City);
}

void sort_floats_comare_it_printf_all_strcuture(float* num,struct student s1,struct student s2,struct student s3,struct student s4,struct student s5)
{
    int i,j;
    float a;
    for (i = 0; i < 4; ++i)
    {
        for (j = i + 1; j <= 4; ++j)
        {
            if (num[i] < num[j])
            {
                a = num[i];
                num[i] = num[j];
                num[j] = a;
            }
        }
    }



    for (i = 0; i <= 4; ++i)
    {
        if(num[i]==s1.CGPA)
        {
            print_of_struct(s1);
        }
        else if(num[i]==s2.CGPA)
        {
            print_of_struct(s2);
        }
        else if(num[i]==s3.CGPA)
        {
            print_of_struct(s3);
        }
        else if(num[i]==s4.CGPA)
        {
            print_of_struct(s4);
        }
        else if(num[i]==s5.CGPA)
        {
            print_of_struct(s5);
        }
    }
}
