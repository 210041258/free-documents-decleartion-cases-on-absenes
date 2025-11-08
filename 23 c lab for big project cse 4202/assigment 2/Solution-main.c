#include <stdio.h>

#include "dnarray.h"

int main(void)
{
    dnarray contra = DArr_New();
    StudentInfo el1;
    puts("--- Intial <Condition> ---\n");
    DArr_Print(&contra);
    DArr_Add(&contra);
    printf("--- Inserted < new student > ---\n");
    DArr_Print(&contra);
}
