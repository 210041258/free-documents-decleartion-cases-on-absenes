#include<stdio.h>
int main(){
    int x,y;
    char z;
    scanf("%d %c %d", &x,&z,&y);

    if(z == '+'){
        float g = add(x,y);
        printf("%.2f",g);
        }
    else if(z == '-'){
        float g = subtract(x,y);
        printf("%.2f",g);
    }
    else if(z == '*'){
        float g = multiple(x,y);
        printf("%.2f",g);
    }
    else if(z == '/'){
        float g = divtion(x,y);
        printf("%.2f",g);
    }
    else if(z == '%'){
        float g = modulos(x,y);
        printf("%.2f",g);
    }
    return 0;
}
int add(int x,int y){

return x+y;
}
int subtract(int x,int y){

return x-y;
}
int divtion(int x,int y){
    if(y==0){
        return 0;
    }
return x/y;
}
int multiple(int x,int y){

return x*y;
}
int modulos(int x,int y){

return x%y;
}
