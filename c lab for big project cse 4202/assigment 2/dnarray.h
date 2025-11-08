#pragma once
#include"StudentInfo.h"

#define DEFAULT_INIT_CAPACITY 2

typedef struct _Dnconnt
{

    StudentInfo* Elements;
    int Count;
    int Capacity;

}dnarray;

dnarray DArr_New(void);

void DArr_Print(dnarray *restrict connt);

void DArr_Free(dnarray *restrict connt);

int DArr_Add(dnarray *restrict connt);

int DArr_RemoveLast(dnarray *restrict connt);

StudentInfo* DArray_Get(dnarray *restrict connt, int index);

int DArr_Set(dnarray *restrict connt, int index, int value);

int DArr_Grow(dnarray *restrict connt);

int DArr_RemoveElementAtIndex(dnarray *restrict connt, int index);
