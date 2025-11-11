#include<stdio.h>
#include <stdlib.h>
#include "SortedLinkedList.h"

int main(){
    int m, n, i;
    SLL_Controller ctrl = SLL_NewController();
    scanf("%d %d", &m, &n);
    n += m;
    for(i=0;i<n;i++){
        scanf("%d", &m);
        SLL_Insert(&ctrl, m);
    }
    SLL_Print(&ctrl);
    return 0;
}

