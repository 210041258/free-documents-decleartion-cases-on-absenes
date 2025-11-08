#include<stdio.h>
int main(){

    int n,c,x;
    scanf("%d",&n);
        int arr1[n];
    int y[n],z=0;
    if((1<=n)&&(n<=(2*(10*10*10*10*10)))){
        if((1<=n)&&(n<=(10*10*10*10*10*10*10*10*10*10))){
            for(x=0;x<n;x++){
                scanf("%d",&y[x]); //entering the list
            }
            for(x=0;x<n;x++){
                if(y[x]!=y[x+1]){ //comparing different values
                        arr1[x]=y[x];
                        if(arr1[x]!=y[c]){
                            z++;
                        }

                }
            }
            printf("%d",z);
        }
    }
    return 0;
}
