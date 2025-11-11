#include <stdio.h>
int main(){
    int x,y,i,j,k;
    scanf("%d %d",&x,&y);
    int arr1[x][y];
    //creating the first matrix
    for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                scanf("%d",&arr1[i][j]);
            }
        }
    int x1,y1;
    scanf("%d %d",&x1,&y1);
    int arr2[x1][y1];
    //creating the second matrix
        for(i=0;i<x1;i++){
            for(j=0;j<y1;j++){
                scanf("%d",&arr2[i][j]);
            }
        }

    if(y==x1){
    // multiplucation
    int multiarr1[x][y1];
    for (i = 0; i < x; i++) {
        for (j = 0; j < y1; j++) {
            multiarr1[i][j] = 0;
            for (k = 0; k < y1; k++) {
                multiarr1[i][j] +=   arr1[i][k]* arr2[k][j];
            }
        }
    }

    for (i = 0; i < x; i++) {
        for (j = 0; j < y1; j++) {
            printf("%5d", multiarr1[i][j]);
        }
        printf("\n");
    }
    }


    return 0;
}
