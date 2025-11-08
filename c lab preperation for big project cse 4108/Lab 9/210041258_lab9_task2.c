#include <stdio.h>
#define TRUE printf("YES");
#define FALSE printf("NO");
int main(){
    int n,z,j,m=0;
    scanf("%d",&n);
    char arr1[n][n];
    if((3<=n)&&(n<=300)){
    if(n%2!=0){
        for(z=0
            sS;z<=n;z++){
            for(j=0;j<n;j++){
                scanf("%c",&arr1[z][j]);
            }
        }


        for(z=-1;z<n;z++){
            for(j=-1;j<n;j++){
                if((arr1[z][j]==arr1[j][z])||(arr1[z][j]==arr1[z+1][j+1])){
                        m=2;
                }
             }
            }
    // showing the result

        if(m==2){
            TRUE
        }
        else{
            FALSE
        }


 }}
    return 0;
}
