#include<stdio.h>
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    int z= xy(x,y);
    printf("%d",z);
    return 0;
}
int xy(int x,int y){
    if(x>y){
            return +1;
    }
    if(y>x){
        return -1;
    }
    if(x==y){
        return 0;
    }

}
