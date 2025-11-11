#include<stdio.h>
#include <stdlib.h>
#include "SortedLinkedList.h"

int main(){
    int value, n, i;
    char Pos[20];
    SLL_Controller ctrl = SLL_NewController();
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf(" %s ", Pos);
        scanf("%d", &value);
        SLL_Insert(&ctrl, value, Pos[0]=='B');
    }
    SLL_Print(&ctrl);
    return 0;
}

