#include<stdio.h>

int sum(int x);

int main(){
    int x,y,z;
    scanf("%d",&x);
    z = sum(x);
    printf("%d",z);
    return 0;
}

int sum(int x){
static int sumation=0;
if((1!=x)){
        sumation+=(2*x);
        sum(--x);
}
else if((1==x)){
        sumation += 1;
        return sumation;
}
return sumation;
}

