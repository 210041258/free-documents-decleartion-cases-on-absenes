#include<stdio.h>
#define TRUE printf("YES");
#define FALSE printf("NO");
int main(){
    int c,r,z,j,m=0;
    scanf("%d %d",&c,&r);

    if((2<=c)&&(c<=100)&&(2<=r)&&(r<=1000)){
    int arr1[c][r],arr2[c][r];
        for(z=0;z<c;z++){
            for(j=0;j<r;j++){
                scanf("%d",&arr1[z][j]);
            }
        }


        for(z=0;z<c;z++){
            for(j=0;j<r;j++){
                //code (process)
                if((arr1[z][j]==arr1[j][z])&&(arr1[z][j]==arr1[z+1][j+1])){
                    m=2;
                }
            }
        }
        // 2 == COMPLETELY SYMETRIC
        if(m==2){
            TRUE
        }
        else{
            FALSE
        }
    }
            // showing the result

    return 0;
}
