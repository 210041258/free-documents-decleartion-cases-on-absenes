#include"dnarray.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

dnarray DArr_New(void)
{
    dnarray connt = (dnarray)
    {
        .Elements = NULL,
        .Count = 0,
        .Capacity = DEFAULT_INIT_CAPACITY
    };

    connt.Elements = ( StudentInfo * )calloc(connt.Capacity , sizeof(StudentInfo));

    if(connt.Elements == NULL)
        exit(1);

    return connt;
}

void DArr_Print(dnarray *restrict connt)
{
    printf("Elements: { ");
    for(int i = 0; i < connt->Count; i++)
    {
        printf("%d- " ,i+1 );
        printf("Name: %s \n", connt->Elements[i].Name);
        printf("ID: %d \n", connt->Elements[i].ID);
        printf("CGPA: %f \n", connt->Elements[i].CGPA);
        printf("Present House Number: %d \n", connt->Elements[i].PresentAddress.HouseNumber);
        printf("Present Road Number: %d \n", connt->Elements[i].PresentAddress.RoadNumber);
        printf("Present City: %s \n", connt->Elements[i].PresentAddress.City);
        printf("Present Country: %s \n", connt->Elements[i].PresentAddress.Country);
        printf("Present ZipCode: %d \n", connt->Elements[i].PresentAddress.ZipCode);
        printf("Permanent House Number: %d \n", connt->Elements[i].PermanentAddress.HouseNumber);
        printf("Permanent Road Number %d \n", connt->Elements[i].PermanentAddress.RoadNumber);
        printf("Permanent City %s \n", connt->Elements[i].PermanentAddress.City);
        printf("Permanent Country %s \n", connt->Elements[i].PermanentAddress.Country);
        printf("Permanent ZipCode %d \n", connt->Elements[i].PermanentAddress.ZipCode);
    }
    printf(
        "}\n"
        "Count: %d\n"
        "Capacity: %d\n",
        connt->Count, connt->Capacity
    );
}

void DArray_Free(dnarray *restrict connt)
{
    free(connt->Elements);
    connt->Capacity = 0;
    connt->Count = 0;
}

int DArr_Grow(dnarray *restrict connt)
{
    StudentInfo* requested = ( StudentInfo * )realloc
    (
        connt->Elements,
        connt->Capacity * 2 * sizeof(int)
    );
    if(requested == NULL)
    {
        return 0;
    }
    else
    {
        connt->Elements = requested;
        connt->Capacity *= 2;
        return 1;
    }
}

int DArr_Add(dnarray *restrict connt)
{
    if(connt->Capacity == 0) return -1;
    if(connt->Count < connt->Capacity)
    {
        printf("Name : ");
        scanf("%s", connt->Elements[connt->Count].Name);
        printf("ID : ");
        scanf("%d", &connt->Elements[connt->Count].ID);
        printf("CGPA : ");
        scanf("%f", &connt->Elements[connt->Count].CGPA);
        printf("Present House Number : ");
        scanf("%d", &connt->Elements[connt->Count].PresentAddress.HouseNumber);
        printf("Present Road Number");
        scanf("%d", &connt->Elements[connt->Count].PresentAddress.RoadNumber);
        printf("Present City : ");
        scanf("%s", connt->Elements[connt->Count].PresentAddress.City);
        printf("Present  Country: ");
        scanf("%s",connt->Elements[connt->Count].PresentAddress.Country);
        printf("Present Zipcode : ");
        scanf("%d", &connt->Elements[connt->Count].PresentAddress.ZipCode);
        printf("Permanent HouseNumber : ");
        scanf("%d", &connt->Elements[connt->Count].PermanentAddress.HouseNumber);
        printf("Permanent road Number  : ");
        scanf("%d",&connt->Elements[connt->Count].PermanentAddress.RoadNumber);
        printf("Permanent City  : ");
        scanf("%s",connt->Elements[connt->Count].PermanentAddress.City);
        printf("Permanent Country  : ");
        scanf("%s",connt->Elements[connt->Count].PermanentAddress.Country);
        printf("Permanent ZipCode  : ");
        scanf("%d", &connt->Elements[connt->Count].PermanentAddress.ZipCode);
        connt->Count++;
    }
    else
    {
        if(DArr_Grow(connt)) return 0;
        printf("Name : ");
        scanf("%s", connt->Elements[connt->Count].Name);
        printf("ID : ");
        scanf("%d", &connt->Elements[connt->Count].ID);
        printf("CGPA : ");
        scanf("%f", &connt->Elements[connt->Count].CGPA);
        printf("Present House Number : ");
        scanf("%d", &connt->Elements[connt->Count].PresentAddress.HouseNumber);
        printf("Present Road Number");
        scanf("%d", &connt->Elements[connt->Count].PresentAddress.RoadNumber);
        printf("Present City : ");
        scanf("%s", connt->Elements[connt->Count].PresentAddress.City);
        printf("Present  Country: ");
        scanf("%s",connt->Elements[connt->Count].PresentAddress.Country);
        printf("Present Zipcode : ");
        scanf("%d", &connt->Elements[connt->Count].PresentAddress.ZipCode);
        printf("Permanent HouseNumber : ");
        scanf("%d", &connt->Elements[connt->Count].PermanentAddress.HouseNumber);
        printf("Permanent road Number  : ");
        scanf("%d",&connt->Elements[connt->Count].PermanentAddress.RoadNumber);
        printf("Permanent City  : ");
        scanf("%s",connt->Elements[connt->Count].PermanentAddress.City);
        printf("Permanent Country  : ");
        scanf("%s",connt->Elements[connt->Count].PermanentAddress.Country);
        printf("Permanent ZipCode  : ");
        scanf("%d", &connt->Elements[connt->Count].PermanentAddress.ZipCode);
        connt->Count++;
    }
    return 1;
}

int DArr_RemoveLast(dnarray *restrict connt)
{
    if(connt->Capacity == 0) return -1;
    if(connt->Count == 0) return 0;

    connt->Count--;
    return 1;
}

StudentInfo* DArr_Get(dnarray *restrict connt, int index)
{
    if(index < connt->Count)
        return &connt->Elements[index];
    else return NULL;
}

int DArr_RemoveElementAtIndex(dnarray *restrict connt, int index)
{

    if(index < connt->Count)
    {
        for(int i=index; i<connt->Count;i++)
        {
            connt->Elements[i] = connt->Elements[i+1];
        }
        connt->Count--;
    }

    else return 0;

}

int DArr_Clearing(dnarray *restrict connt)
{
    if(connt->Count < 1) return 0;

    while(connt->Count != 0){
        for(int i=0; i<connt->Count; i++)
        {
            connt->Elements[i] = connt->Elements[i+1];
        }
        connt->Count--;
    }


}
