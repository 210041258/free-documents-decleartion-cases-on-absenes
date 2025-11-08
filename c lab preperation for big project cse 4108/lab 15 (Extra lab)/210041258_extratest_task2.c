#include<stdio.h>
int main(){
    int i,x,y,t;
    scanf("%d",&t);
    if(t<15){
    if((x<1000000001)&(y<1000000001)){
    for(i=0;i<t;i++){
        scanf("%d %d",&x,&y);
        operation(x,y);
    }
}}
    return 0;
}

void operation(int x,int y){
    if(x>y){
    printf(">\n");
    }
    else if(x<y){
    printf("<\n");
    }
    else if(x==y){
    printf("=\n");
    }

}
