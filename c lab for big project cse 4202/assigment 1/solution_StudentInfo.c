#include <stdio.h>
#include "StudentInfo.h"

FILE *file;
StudentInfo read_stud(StudentInfo student);
StudentInfo fread_info(StudentInfo student);
void print_stud(StudentInfo student);
void fwrite_info(StudentInfo student);

int main(){
    file = fopen("db.txt","a+");
    if(file == NULL){
            file = fopen("db.txt","w+");
    }
    StudentInfo old_student;
    old_student = read_stud(old_student);
    printf("\n");
    print_stud(old_student);
    fwrite_info(old_student);
    old_student = fread_info(old_student);
    printf("\n");
    print_stud(old_student);
    fclose(file);
return 0;
}


StudentInfo fread_info(StudentInfo student){
fscanf(file,"\nThe Name of the student : %s \n",student.Name);
fscanf(file,"The ID of the student : %d \n",&student.ID);
fscanf(file,"The CGPA of the student : %.2f \n",&student.CGPA);
fscanf(file,"The Permanent Address of the student : \nCountry: %s \nCity : %s \nZipCode : %d \nRoadNumber : %d \nHouseNumber : %d \n",student.PermanentAddress.Country,student.PermanentAddress.City,&student.PermanentAddress.ZipCode,&student.PermanentAddress.RoadNumber,&student.PermanentAddress.HouseNumber);
fscanf(file,"The Present Address of the student : \nCountry: %s \nCity : %s \nZipCode : %d \nRoadNumber : %d \nHouseNumber : %d \n",student.PresentAddress.Country,student.PresentAddress.City,&student.PresentAddress.ZipCode,&student.PresentAddress.RoadNumber,&student.PresentAddress.HouseNumber);
return student;
}

void fwrite_info(StudentInfo student){
fprintf(file,"\nThe Name of the student : %s \n",student.Name);
fprintf(file,"The ID of the student : %d \n",student.ID);
fprintf(file,"The CGPA of the student : %.2f \n",student.CGPA);
fprintf(file,"The Permanent Address of the student : \nCountry: %s \nCity : %s \nZipCode : %d \nRoadNumber : %d \nHouseNumber : %d \n",student.PermanentAddress.Country,student.PermanentAddress.City,student.PermanentAddress.ZipCode,student.PermanentAddress.RoadNumber,student.PermanentAddress.HouseNumber);
fprintf(file,"The Present Address of the student : \nCountry: %s \nCity : %s \nZipCode : %d \nRoadNumber : %d \nHouseNumber : %d \n",student.PresentAddress.Country,student.PresentAddress.City,student.PresentAddress.ZipCode,student.PresentAddress.RoadNumber,student.PresentAddress.HouseNumber);
}

StudentInfo read_stud(StudentInfo student){
printf("The Name of the student : ");
scanf("%s",student.Name);
printf("The ID of the student : ");
scanf("%d",&student.ID);
printf("The CGPA of the student : ");
scanf("%f",&student.CGPA);
printf("The Permanent Address of the student [Country City ZipCode RoadNumber HouseNumber] : \n");
scanf("%s %s %d %d %d",student.PermanentAddress.Country,student.PermanentAddress.City,&student.PermanentAddress.ZipCode,&student.PermanentAddress.RoadNumber,&student.PermanentAddress.HouseNumber);
printf("The Present Address of the student [Country City ZipCode RoadNumber HouseNumber] : \n");
scanf("%s %s %d %d %d",student.PresentAddress.Country,student.PresentAddress.City,&student.PresentAddress.ZipCode,&student.PresentAddress.RoadNumber,&student.PresentAddress.HouseNumber);
return student;
}

void print_stud(StudentInfo student){
printf("The Name of the student : %s \n",student.Name);
printf("The ID of the student : %d \n",student.ID);
printf("The CGPA of the student : %.2f \n",student.CGPA);
printf("The Permanent Address of the student : \nCountry: %s \nCity : %s \nZipCode %d \nRoadNumber : %d \nHouseNumber : %d \n",student.PermanentAddress.Country,student.PermanentAddress.City,student.PermanentAddress.ZipCode,student.PermanentAddress.RoadNumber,student.PermanentAddress.HouseNumber);
printf("The Present Address of the student : \nCountry: %s \nCity : %s \nZipCode %d \nRoadNumber : %d \nHouseNumber : %d \n",student.PresentAddress.Country,student.PresentAddress.City,student.PresentAddress.ZipCode,student.PresentAddress.RoadNumber,student.PresentAddress.HouseNumber);

}
