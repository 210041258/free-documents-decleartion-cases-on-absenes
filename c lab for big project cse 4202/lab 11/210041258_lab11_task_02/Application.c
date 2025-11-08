#include <stdio.h>

#include "SortedLinkedList.h"

int main(void)
{
    int x,v,value=0;
    scanf("%d",&x);
    SLL_Controller ctrl = SLL_NewController();
    for(v=0;v<x;++v){
    scanf("%d",&value);
    SLL_Insert(&ctrl, value);
    }
    SLL_Print(&ctrl);
    return 0;
}
